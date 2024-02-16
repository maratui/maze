#include "facade.h"

using namespace s21;

Scene *Facade::GetScene() noexcept { return &scene_; }

void Facade::ClearScene() { scene_.ClearScene(); }

void Facade::LoadMaze(const std::string &path) {
  file_reader_.ReadMazeFile(vertical_walls_, horizontal_walls_, path);
  maze_.SetMaze(vertical_walls_, horizontal_walls_);
}

void Facade::GenerateMaze(const std::string &path, unsigned raws,
                          unsigned cols) {
  maze_.GenerateMaze(vertical_walls_, horizontal_walls_, raws, cols);
  file_reader_.WriteMazeToFile(vertical_walls_, horizontal_walls_, path);
}

void Facade::DrawMaze() { scene_.DrawMaze(vertical_walls_, horizontal_walls_); }

void Facade::SolvMaze() {
  std::vector<Point> solving_points = scene_.GetSolvingPoints();

  solving_points_ = maze_.SolvMaze(solving_points);
  scene_.DrawSolving(solving_points_);
}
