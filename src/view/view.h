#ifndef A1_MAZE_VIEW_VIEW_H_
#define A1_MAZE_VIEW_VIEW_H_

#include <QEventLoop>
#include <QFileDialog>
#include <QInputDialog>
#include <QLabel>
#include <QLineEdit>
#include <QMessageBox>
#include <QWidget>

#include "../controller/controller.h"
#include "button.h"
#include "draw.h"

namespace s21 {
class View : public QWidget {
  Q_OBJECT

 public:
  View() = delete;
  explicit View(Controller *controller);

 private slots:
  void LoadMazeButtonClicked();
  void GenerateMazeButtonClicked();
  void SolvMazeButtonClicked();
  void ClearSolvingButtonClicked();

 private:
  static constexpr unsigned kMaxSize = 50U;

  void CreateDraw();
  void CreateConnectButtons();
  void CreateSolvMazeLabel();
  void CreateGridLayout();
  void InputMazeSize(unsigned &raws, unsigned &cols);

  Controller *controller_{};
  Draw *draw_{};
  Button *load_maze_button_{};
  Button *generate_maze_button_{};
  Button *solv_maze_button_{};
  Button *clear_solving_button_{};
  QLabel *solv_maze_label_{};
  QGridLayout *grid_layout_{};
};
}  // namespace s21

#endif  // A1_MAZE_VIEW_VIEW_H_
