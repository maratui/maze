#include "maze.h"

using namespace s21;

std::vector<Point> &Maze::SolvMaze(const std::vector<Point> &solving_points) {
  solving_points_.clear();
  if (IsValidRawsCols() && (solving_points.size() == 2UL)) {
    bool is_solv = true;

    InitMazeSolving(solving_points);
    while (is_solv && (IsSolvingFinished() == false)) {
      if (NextPoint()) {
        stack_.push(point_);
      } else {
        is_solv = ComebackPoint();
      }
    }
    if (is_solv) {
    } else {
      solving_points_.clear();
    }
  }

  return solving_points_;
}

void Maze::InitMazeSolving(const std::vector<Point> &solving_points) {
  point_.raw = solving_points[0].raw;
  point_.col = solving_points[0].col;
  second_point_.raw = solving_points[1].raw;
  second_point_.col = solving_points[1].col;

  while (stack_.empty() == false) {
    stack_.pop();
  }
  stack_.push(point_);

  solving_points_.clear();
  solving_points_.push_back(point_);

  for (auto i = 0U; i < raws_; i++) {
    for (auto j = 0U; j < cols_; j++) {
      maze_solving_[i][j] = 0U;
    }
  }
  maze_solving_[point_.raw][point_.col] = 1U;
}

bool Maze::IsSolvingFinished() noexcept {
  return ((point_.raw == second_point_.raw) &&
          (point_.col == second_point_.col));
}

bool Maze::NextPoint() {
  bool is_next_point = true;

  if (NextCol()) {
  } else if (NextRaw()) {
  } else {
    is_next_point = false;
  }
  if (is_next_point) {
    solving_points_.push_back(point_);
    maze_solving_[point_.raw][point_.col] = 1U;
  }

  return is_next_point;
}

bool Maze::NextCol() noexcept {
  bool is_next_col = true;

  if ((point_.col < cols_) && (vertical_walls_[point_.raw][point_.col] == 0U) &&
      (maze_solving_[point_.raw][point_.col + 1U] == 0U)) {
    point_.col += 1U;
  } else if ((point_.col > 0U) &&
             (vertical_walls_[point_.raw][point_.col - 1U] == 0U) &&
             (maze_solving_[point_.raw][point_.col - 1U] == 0U)) {
    point_.col -= 1U;
  } else {
    is_next_col = false;
  }

  return is_next_col;
}

bool Maze::NextRaw() noexcept {
  bool is_next_raw = true;

  if ((point_.raw < raws_) &&
      (horizontal_walls_[point_.raw][point_.col] == 0U) &&
      (maze_solving_[point_.raw + 1U][point_.col] == 0U)) {
    point_.raw += 1U;
  } else if ((point_.raw > 0U) &&
             (horizontal_walls_[point_.raw - 1][point_.col] == 0U) &&
             (maze_solving_[point_.raw - 1U][point_.col] == 0U)) {
    point_.raw -= 1U;
  } else {
    is_next_raw = false;
  }

  return is_next_raw;
}

bool Maze::ComebackPoint() {
  bool is_combacked = true;

  if (stack_.empty() == false) {
    stack_.pop();
  }
  if (stack_.empty() == false) {
    point_ = stack_.top();
  } else {
    is_combacked = false;
  }

  if (is_combacked) {
    while ((solving_points_.empty() == false) &&
           (((point_.raw == solving_points_.back().raw) &&
             (point_.col == solving_points_.back().col)) == false)) {
      solving_points_.pop_back();
    }
  }

  return is_combacked;
}
