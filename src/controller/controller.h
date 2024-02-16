#ifndef A1_MAZE_CONTROLLER_CONTROLLER_H_
#define A1_MAZE_CONTROLLER_CONTROLLER_H_

#include "../facade/facade.h"

namespace s21 {
class Controller {
 public:
  Controller() = delete;
  explicit Controller(Facade *facade);

  Scene *GetScene() noexcept;
  void ClearScene();
  void LoadMaze(const std::string &path);
  void GenerateMaze(const std::string &path, unsigned raws, unsigned cols);
  void DrawMaze();
  void SolvMaze();

 private:
  Facade *facade_{};
};
}  // namespace s21

#endif  // A1_MAZE_CONTROLLER_CONTROLLER_H_
