#ifndef A1_MAZE_FACADE_FACADE_H_
#define A1_MAZE_FACADE_FACADE_H_

#include <string>
#include <vector>

#include "../model/maze.h"
#include "file_reader.h"
#include "scene.h"

namespace s21 {
class Facade {
 public:
  Scene *GetScene() noexcept;
  void ClearScene();
  void LoadMaze(const std::string &path);
  void GenerateMaze(const std::string &path, unsigned raws, unsigned cols);
  void DrawMaze();
  void SolvMaze();

 private:
  FileReader file_reader_;
  Scene scene_;
  Maze maze_;

  std::vector<std::vector<unsigned>> vertical_walls_;
  std::vector<std::vector<unsigned>> horizontal_walls_;
  std::vector<Point> solving_points_;
};
}  // namespace s21

#endif  // A1_MAZE_FACADE_FACADE_H_
