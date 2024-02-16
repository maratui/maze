#include "maze.h"

using namespace s21;

void Maze::SetMaze(const std::vector<std::vector<unsigned>> &vertical_walls,
                   const std::vector<std::vector<unsigned>> &horizontal_walls) {
  unsigned raws = vertical_walls.size();

  InitMaze();
  if (IsValidRaws(raws)) {
    unsigned cols = vertical_walls[0].size();

    if (IsValidCols(cols)) {
      raws_ = raws;
      cols_ = cols;
      vertical_walls_ = vertical_walls;
      horizontal_walls_ = horizontal_walls;
      AssignMazeSolving();
    }
  }
}

bool Maze::IsValidRaws(unsigned raws) noexcept {
  return ((raws >= kMinSize) && (raws <= kMaxSize));
}
bool Maze::IsValidCols(unsigned cols) noexcept {
  return ((cols >= kMinSize) && (cols <= kMaxSize));
}
bool Maze::IsValidRawsCols() noexcept {
  return ((raws_ >= kMinSize) && (raws_ <= kMaxSize) && (cols_ >= kMinSize) &&
          (cols_ <= kMaxSize));
}
bool Maze::IsValidRawsCols(unsigned raws, unsigned cols) noexcept {
  return (IsValidRaws(raws) && IsValidCols(cols));
}

void Maze::InitMaze() {
  raws_ = 0U;
  cols_ = 0U;
  vertical_walls_.clear();
  horizontal_walls_.clear();
  maze_solving_.clear();
  vertical_walls_raw_.clear();
  horizontal_walls_raw_.clear();
  area_number_ = 0U;
}

void Maze::AssignMazeSolving() {
  std::vector<unsigned> unsigned_vector;

  unsigned_vector.assign(cols_, 0U);
  maze_solving_.assign(raws_, unsigned_vector);
}
