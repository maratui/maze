#ifndef A1_MAZE_MODEL_MAZE_H_
#define A1_MAZE_MODEL_MAZE_H_

#include <random>
#include <stack>
#include <vector>

#include "point.h"

namespace s21 {
class Maze {
 public:
  void SetMaze(const std::vector<std::vector<unsigned>> &vertical_walls,
               const std::vector<std::vector<unsigned>> &horizontal_walls);
  void GenerateMaze(std::vector<std::vector<unsigned>> &vertical_walls,
                    std::vector<std::vector<unsigned>> &horizontal_walls,
                    unsigned raws, unsigned cols);
  std::vector<Point> &SolvMaze(const std::vector<Point> &solving_points);

 private:
  static constexpr double kDistributionParameter = 1.0;
  static constexpr unsigned kMinSize = 1U;
  static constexpr unsigned kMaxSize = 50U;

  bool IsValidRaws(unsigned raws) noexcept;
  bool IsValidCols(unsigned cols) noexcept;
  bool IsValidRawsCols() noexcept;
  bool IsValidRawsCols(unsigned raws, unsigned cols) noexcept;
  void InitMaze();
  void AssignMazeSolving();

  void InitMazeGeneration(unsigned raws, unsigned cols);
  void VerticalWallsRaw(unsigned i);
  bool IsDifferentAreas(unsigned i, unsigned j) noexcept;
  void UniteAreas(unsigned area_dest, unsigned area_src) noexcept;
  void HorizontalWallsRaw(unsigned i);
  bool RandomAction();

  void InitMazeSolving(const std::vector<Point> &solving_points);
  bool IsSolvingFinished() noexcept;
  bool NextPoint();
  bool NextCol() noexcept;
  bool NextRaw() noexcept;
  bool ComebackPoint();

  std::vector<std::vector<unsigned>> vertical_walls_;
  std::vector<std::vector<unsigned>> horizontal_walls_;
  unsigned raws_{};
  unsigned cols_{};

  std::vector<std::vector<unsigned>> maze_solving_;
  std::vector<unsigned> vertical_walls_raw_;
  std::vector<unsigned> horizontal_walls_raw_;
  unsigned area_number_{};
  bool is_random_action_{};

  std::stack<Point> stack_;
  std::vector<Point> solving_points_;
  Point point_{};
  Point second_point_{};
};
}  // namespace s21

#endif  // A1_MAZE_MODEL_MAZE_H_
