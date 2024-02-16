#include "view.h"

using namespace s21;

View::View(Controller *controller) : controller_(controller) {
  setWindowTitle("Maze");
  CreateDraw();
  CreateConnectButtons();
  CreateSolvMazeLabel();
  CreateGridLayout();
}

void View::CreateDraw() { draw_ = new Draw(controller_->GetScene()); }

void View::CreateConnectButtons() {
  load_maze_button_ = new Button("Загрузить лабиринт", false);
  generate_maze_button_ = new Button("Сгенерировать лабиринт", false);
  solv_maze_button_ = new Button("Решить лабиринт", false);
  clear_solving_button_ = new Button("Очистить решение лабиринта", false);

  connect(load_maze_button_, SIGNAL(clicked()), this,
          SLOT(LoadMazeButtonClicked()));
  connect(generate_maze_button_, SIGNAL(clicked()), this,
          SLOT(GenerateMazeButtonClicked()));
  connect(solv_maze_button_, SIGNAL(clicked()), this,
          SLOT(SolvMazeButtonClicked()));
  connect(clear_solving_button_, SIGNAL(clicked()), this,
          SLOT(ClearSolvingButtonClicked()));
}

void View::CreateSolvMazeLabel() {
  solv_maze_label_ = new QLabel();
  solv_maze_label_->setAlignment(Qt::AlignCenter);
  solv_maze_label_->setText(
      "Для решения лабиринта,\n"
      "пользователем задаются начальная и конечная точки\n"
      "кликом левой кнопкой мыши по месту на лабиринте");
}

void View::CreateGridLayout() {
  grid_layout_ = new QGridLayout(this);
  grid_layout_->addWidget(draw_, 0, 0, 1, 2, Qt::AlignTop);
  grid_layout_->addWidget(load_maze_button_, 1, 0, 1, 1, Qt::AlignTop);
  grid_layout_->addWidget(generate_maze_button_, 1, 1, 1, 1, Qt::AlignTop);
  grid_layout_->addWidget(solv_maze_button_, 2, 0, 1, 1, Qt::AlignTop);
  grid_layout_->addWidget(clear_solving_button_, 2, 1, 1, 1, Qt::AlignTop);
  grid_layout_->addWidget(solv_maze_label_, 3, 0, 1, 2, Qt::AlignTop);
  grid_layout_->setSizeConstraint(QLayout::SetFixedSize);
}

void View::LoadMazeButtonClicked() {
  QString maze_path = QFileDialog::getOpenFileName(this, "Open the maze", ".",
                                                   "the maze (*.maze)");

  if (maze_path != "") {
    controller_->LoadMaze(maze_path.toStdString());
    controller_->ClearScene();
    controller_->DrawMaze();
  }
}

void View::GenerateMazeButtonClicked() {
  QString maze_path = QFileDialog::getSaveFileName(this, "Save the maze", ".",
                                                   "the maze (*.maze)");

  if (maze_path != "") {
    unsigned raws{};
    unsigned cols{};

    InputMazeSize(raws, cols);
    controller_->GenerateMaze(maze_path.toStdString(), raws, cols);
    controller_->ClearScene();
    controller_->DrawMaze();
  };
}

void View::InputMazeSize(unsigned &raws, unsigned &cols) {
  bool button_ok;
  QString raws_str = QInputDialog::getText(
      this, "Размерность лабиринта",
      "Введите количество строк:", QLineEdit::Normal, "", &button_ok);

  if (button_ok) {
    QString cols_str = QInputDialog::getText(
        this, "Размерность лабиринта",
        "Введите количество столбцов:", QLineEdit::Normal, "", &button_ok);

    if (button_ok) {
      try {
        raws = (unsigned)raws_str.toInt();
        raws = (raws > kMaxSize) ? kMaxSize : raws;
      } catch (...) {
        raws = 0U;
      }
      try {
        cols = (unsigned)cols_str.toInt();
        cols = (cols > kMaxSize) ? kMaxSize : cols;
      } catch (...) {
        cols = 0U;
      }
    }
  }

  QMessageBox msg(this);
  msg.setText("Вы ввели размерность лабиринта: " + QString::number(raws) +
              " x " + QString::number(cols));
  msg.exec();
}

void View::SolvMazeButtonClicked() { controller_->SolvMaze(); }

void View::ClearSolvingButtonClicked() {
  controller_->ClearScene();
  controller_->DrawMaze();
}
