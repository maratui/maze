#include "tests.h"

TEST(TestMaze, ReadMazeFile) {
  s21::FileReader file_reader;
  std::vector<std::vector<unsigned>> vertical_walls;
  std::vector<std::vector<unsigned>> horizontal_walls;

  file_reader.ReadMazeFile(vertical_walls, horizontal_walls,
                           "../tests/good_maze.maze");

  EXPECT_EQ(4, vertical_walls.size());
  EXPECT_EQ(4, vertical_walls[0].size());
  EXPECT_EQ(4, horizontal_walls.size());
  EXPECT_EQ(4, horizontal_walls[0].size());

  EXPECT_EQ(0, vertical_walls[0][0]);
  EXPECT_EQ(0, vertical_walls[0][1]);
  EXPECT_EQ(0, vertical_walls[0][2]);
  EXPECT_EQ(1, vertical_walls[0][3]);

  EXPECT_EQ(1, vertical_walls[1][0]);
  EXPECT_EQ(0, vertical_walls[1][1]);
  EXPECT_EQ(1, vertical_walls[1][2]);
  EXPECT_EQ(1, vertical_walls[1][3]);

  EXPECT_EQ(0, vertical_walls[2][0]);
  EXPECT_EQ(1, vertical_walls[2][1]);
  EXPECT_EQ(0, vertical_walls[2][2]);
  EXPECT_EQ(1, vertical_walls[2][3]);

  EXPECT_EQ(0, vertical_walls[3][0]);
  EXPECT_EQ(0, vertical_walls[3][1]);
  EXPECT_EQ(0, vertical_walls[3][2]);
  EXPECT_EQ(1, vertical_walls[3][3]);

  EXPECT_EQ(1, horizontal_walls[0][0]);
  EXPECT_EQ(0, horizontal_walls[0][1]);
  EXPECT_EQ(1, horizontal_walls[0][2]);
  EXPECT_EQ(0, horizontal_walls[0][3]);

  EXPECT_EQ(0, horizontal_walls[1][0]);
  EXPECT_EQ(0, horizontal_walls[1][1]);
  EXPECT_EQ(1, horizontal_walls[1][2]);
  EXPECT_EQ(0, horizontal_walls[1][3]);

  EXPECT_EQ(1, horizontal_walls[2][0]);
  EXPECT_EQ(1, horizontal_walls[2][1]);
  EXPECT_EQ(0, horizontal_walls[2][2]);
  EXPECT_EQ(1, horizontal_walls[2][3]);

  EXPECT_EQ(1, horizontal_walls[3][0]);
  EXPECT_EQ(1, horizontal_walls[3][1]);
  EXPECT_EQ(1, horizontal_walls[3][2]);
  EXPECT_EQ(1, horizontal_walls[3][3]);
}

TEST(TestMaze, WriteMazeToFile) {
  s21::FileReader file_reader;
  std::vector<std::vector<unsigned>> vertical_walls;
  std::vector<std::vector<unsigned>> horizontal_walls;

  file_reader.ReadMazeFile(vertical_walls, horizontal_walls,
                           "../tests/good_maze.maze");

  file_reader.WriteMazeToFile(vertical_walls, horizontal_walls, "test.maze");
  vertical_walls.clear();
  horizontal_walls.clear();
  file_reader.ReadMazeFile(vertical_walls, horizontal_walls, "test.maze");

  EXPECT_EQ(4, vertical_walls.size());
  EXPECT_EQ(4, vertical_walls[0].size());
  EXPECT_EQ(4, horizontal_walls.size());
  EXPECT_EQ(4, horizontal_walls[0].size());

  EXPECT_EQ(0, vertical_walls[0][0]);
  EXPECT_EQ(0, vertical_walls[0][1]);
  EXPECT_EQ(0, vertical_walls[0][2]);
  EXPECT_EQ(1, vertical_walls[0][3]);

  EXPECT_EQ(1, vertical_walls[1][0]);
  EXPECT_EQ(0, vertical_walls[1][1]);
  EXPECT_EQ(1, vertical_walls[1][2]);
  EXPECT_EQ(1, vertical_walls[1][3]);

  EXPECT_EQ(0, vertical_walls[2][0]);
  EXPECT_EQ(1, vertical_walls[2][1]);
  EXPECT_EQ(0, vertical_walls[2][2]);
  EXPECT_EQ(1, vertical_walls[2][3]);

  EXPECT_EQ(0, vertical_walls[3][0]);
  EXPECT_EQ(0, vertical_walls[3][1]);
  EXPECT_EQ(0, vertical_walls[3][2]);
  EXPECT_EQ(1, vertical_walls[3][3]);

  EXPECT_EQ(1, horizontal_walls[0][0]);
  EXPECT_EQ(0, horizontal_walls[0][1]);
  EXPECT_EQ(1, horizontal_walls[0][2]);
  EXPECT_EQ(0, horizontal_walls[0][3]);

  EXPECT_EQ(0, horizontal_walls[1][0]);
  EXPECT_EQ(0, horizontal_walls[1][1]);
  EXPECT_EQ(1, horizontal_walls[1][2]);
  EXPECT_EQ(0, horizontal_walls[1][3]);

  EXPECT_EQ(1, horizontal_walls[2][0]);
  EXPECT_EQ(1, horizontal_walls[2][1]);
  EXPECT_EQ(0, horizontal_walls[2][2]);
  EXPECT_EQ(1, horizontal_walls[2][3]);

  EXPECT_EQ(1, horizontal_walls[3][0]);
  EXPECT_EQ(1, horizontal_walls[3][1]);
  EXPECT_EQ(1, horizontal_walls[3][2]);
  EXPECT_EQ(1, horizontal_walls[3][3]);
}

TEST(TestMaze, SolvMaze) {
  s21::Maze maze;
  s21::FileReader file_reader;
  std::vector<std::vector<unsigned>> vertical_walls;
  std::vector<std::vector<unsigned>> horizontal_walls;
  std::vector<s21::Point> solving_points;
  std::vector<s21::Point> maze_solving;

  file_reader.ReadMazeFile(vertical_walls, horizontal_walls,
                           "../tests/good_maze.maze");
  maze.SetMaze(vertical_walls, horizontal_walls);

  solving_points.clear();
  solving_points.push_back({0U, 0U});
  solving_points.push_back({3U, 3U});
  maze_solving = maze.SolvMaze(solving_points);

  EXPECT_EQ(9, maze_solving.size());

  EXPECT_EQ(0, maze_solving[0].raw);
  EXPECT_EQ(0, maze_solving[0].col);

  EXPECT_EQ(0, maze_solving[1].raw);
  EXPECT_EQ(1, maze_solving[1].col);

  EXPECT_EQ(0, maze_solving[2].raw);
  EXPECT_EQ(2, maze_solving[2].col);

  EXPECT_EQ(0, maze_solving[3].raw);
  EXPECT_EQ(3, maze_solving[3].col);

  EXPECT_EQ(1, maze_solving[4].raw);
  EXPECT_EQ(3, maze_solving[4].col);

  EXPECT_EQ(2, maze_solving[5].raw);
  EXPECT_EQ(3, maze_solving[5].col);

  EXPECT_EQ(2, maze_solving[6].raw);
  EXPECT_EQ(2, maze_solving[6].col);

  EXPECT_EQ(3, maze_solving[7].raw);
  EXPECT_EQ(2, maze_solving[7].col);

  EXPECT_EQ(3, maze_solving[8].raw);
  EXPECT_EQ(3, maze_solving[8].col);

  solving_points.clear();
  solving_points.push_back({3U, 3U});
  solving_points.push_back({0U, 0U});
  maze_solving = maze.SolvMaze(solving_points);

  EXPECT_EQ(9, maze_solving.size());

  EXPECT_EQ(3, maze_solving[0].raw);
  EXPECT_EQ(3, maze_solving[0].col);

  EXPECT_EQ(3, maze_solving[1].raw);
  EXPECT_EQ(2, maze_solving[1].col);

  EXPECT_EQ(2, maze_solving[2].raw);
  EXPECT_EQ(2, maze_solving[2].col);

  EXPECT_EQ(2, maze_solving[3].raw);
  EXPECT_EQ(3, maze_solving[3].col);

  EXPECT_EQ(1, maze_solving[4].raw);
  EXPECT_EQ(3, maze_solving[4].col);

  EXPECT_EQ(0, maze_solving[5].raw);
  EXPECT_EQ(3, maze_solving[5].col);

  EXPECT_EQ(0, maze_solving[6].raw);
  EXPECT_EQ(2, maze_solving[6].col);

  EXPECT_EQ(0, maze_solving[7].raw);
  EXPECT_EQ(1, maze_solving[7].col);

  EXPECT_EQ(0, maze_solving[8].raw);
  EXPECT_EQ(0, maze_solving[8].col);

  file_reader.ReadMazeFile(vertical_walls, horizontal_walls,
                           "../tests/bad_maze.maze");
  maze.SetMaze(vertical_walls, horizontal_walls);

  solving_points.clear();
  solving_points.push_back({0U, 0U});
  solving_points.push_back({3U, 3U});
  maze_solving = maze.SolvMaze(solving_points);

  EXPECT_EQ(0, maze_solving.size());
}

TEST(TestMaze, GenerateMaze) {
  s21::Maze maze;
  std::vector<std::vector<unsigned>> vertical_walls;
  std::vector<std::vector<unsigned>> horizontal_walls;
  std::vector<s21::Point> solving_points;
  std::vector<s21::Point> forward_solving;
  std::vector<s21::Point> backward_solving;
  constexpr unsigned kSize = 10U;

  maze.GenerateMaze(vertical_walls, horizontal_walls, kSize, kSize);

  for (auto i = 0U; i < kSize; i++) {
    for (auto j = 0U; j < kSize; j++) {
      if ((i != 0U) || (j != 0U)) {
        solving_points.clear();
        solving_points.push_back({0U, 0U});
        solving_points.push_back({i, j});
        forward_solving = maze.SolvMaze(solving_points);
        EXPECT_TRUE(forward_solving.size() > 0UL);

        solving_points.clear();
        solving_points.push_back({i, j});
        solving_points.push_back({0U, 0U});
        backward_solving = maze.SolvMaze(solving_points);
        EXPECT_TRUE(backward_solving.size() > 0UL);

        EXPECT_EQ(forward_solving.size(), backward_solving.size());
        for (auto k = 0UL; k < forward_solving.size(); k++) {
          if ((forward_solving[k].raw !=
               backward_solving[forward_solving.size() - k - 1UL].raw) ||
              (forward_solving[k].col !=
               backward_solving[forward_solving.size() - k - 1UL].col)) {
            EXPECT_TRUE(false);
          }
        }
      }
    }
  }
}
