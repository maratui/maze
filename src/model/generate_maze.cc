#include "maze.h"

using namespace s21;

void Maze::GenerateMaze(std::vector<std::vector<unsigned>> &vertical_walls,
                        std::vector<std::vector<unsigned>> &horizontal_walls,
                        unsigned raws, unsigned cols) {
  InitMaze();

  if (IsValidRawsCols(raws, cols)) {
    InitMazeGeneration(raws, cols);
    is_random_action_ = true;
    for (auto i = 0U; i < raws_; i++) {
      if (i == raws_ - 1U) {
        is_random_action_ = false;
      }
      VerticalWallsRaw(i);
      HorizontalWallsRaw(i);
      vertical_walls_.push_back(vertical_walls_raw_);
      horizontal_walls_.push_back(horizontal_walls_raw_);
    }
  }

  vertical_walls = vertical_walls_;
  horizontal_walls = horizontal_walls_;
}

void Maze::InitMazeGeneration(unsigned raws, unsigned cols) {
  raws_ = raws;
  cols_ = cols;
  AssignMazeSolving();
  for (auto j = 0U; j < cols_; j++) {
    area_number_ += 1U;
    maze_solving_[0][j] = area_number_;
  }
}

void Maze::VerticalWallsRaw(unsigned i) {
  vertical_walls_raw_.assign(cols_, 1U);
  for (auto j = 0U; j < cols_ - 1U; j++) {
    if (IsDifferentAreas(i, j) && RandomAction()) {
      UniteAreas(maze_solving_[i][j + 1U], maze_solving_[i][j]);
      vertical_walls_raw_[j] = 0U;
    }
  }
  if (i < raws_ - 1U) {
    for (auto k = 0U; k < cols_; k++) {
      area_number_ += 1U;
      maze_solving_[i + 1U][k] = area_number_;
    }
  }
}

bool Maze::IsDifferentAreas(unsigned i, unsigned j) noexcept {
  bool is_different_area{};

  if (maze_solving_[i][j] == maze_solving_[i][j + 1U]) {
    is_different_area = false;
  } else {
    is_different_area = true;
  }

  return is_different_area;
}

void Maze::UniteAreas(unsigned area_dest, unsigned area_src) noexcept {
  for (auto i = 0U; i < raws_; i++) {
    for (auto j = 0U; j < cols_; j++) {
      if (maze_solving_[i][j] == area_dest) {
        maze_solving_[i][j] = area_src;
      }
    }
  }
}

void Maze::HorizontalWallsRaw(unsigned i) {
  horizontal_walls_raw_.assign(cols_, 1U);
  if (i < raws_ - 1U) {
    bool is_horizontal_wall_ = true;

    for (auto j = 0U; j < cols_; j++) {
      if (((vertical_walls_raw_[j] == 0U) && RandomAction()) ||
          ((vertical_walls_raw_[j] == 1U) && is_horizontal_wall_)) {
        maze_solving_[i + 1U][j] = maze_solving_[i][j];
        horizontal_walls_raw_[j] = 0U;
        is_horizontal_wall_ = false;
      }
      if (vertical_walls_raw_[j] == 1U) {
        is_horizontal_wall_ = true;
      }
    }
  }
}

bool Maze::RandomAction() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<> dis(-kDistributionParameter,
                                       kDistributionParameter);
  bool random_action{};

  if (is_random_action_) {
    random_action = dis(gen) > 0.0;
  } else {
    random_action = true;
  }

  return random_action;
}
