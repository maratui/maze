#include "scene.h"

using namespace s21;

Scene::Scene() {
  setSceneRect(0, 0, kSceneWidth, kSceneHeight);
  ClearScene();
}

void Scene::ClearScene() {
  solving_points_count_ = 0U;
  solving_points_.clear();
  is_drawn_ = false;
  clear();
}

void Scene::DrawMaze(
    const std::vector<std::vector<unsigned>> &vertical_walls,
    const std::vector<std::vector<unsigned>> &horizontal_walls) {
  raws_ = vertical_walls.size();
  if (raws_ > 0U) {
    vertical_wall_size_ = (double)(height() - 2) / (double)raws_;
    cols_ = vertical_walls[0].size();
    if (cols_ > 0U) {
      horizontal_wall_size_ = (double)(width() - 2) / (double)cols_;
      clear();
      addLine(1, 1, 1, height() - 1,
              QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
      addLine(1, 1, width() - 1, 1,
              QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
      DrawVericalHorizontalWalls(vertical_walls, horizontal_walls);
      is_drawn_ = true;
    }
  }
}

void Scene::DrawVericalHorizontalWalls(
    const std::vector<std::vector<unsigned>> &vertical_walls,
    const std::vector<std::vector<unsigned>> &horizontal_walls) {
  double x{};
  double y{};

  for (auto i = 0UL; i < raws_; i++) {
    for (auto j = 0UL; j < cols_; j++) {
      if (vertical_walls[i][j] == 1) {
        x = (j + 1UL) * horizontal_wall_size_ + 1.0;
        y = i * vertical_wall_size_ + 1.0;
        addLine(x, y, x, (y + vertical_wall_size_),
                QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
      }
      if (horizontal_walls[i][j] == 1) {
        x = j * horizontal_wall_size_ + 1.0;
        y = (i + 1UL) * vertical_wall_size_ + 1.0;
        addLine(x, y, (x + horizontal_wall_size_), y,
                QPen(Qt::black, 2, Qt::SolidLine, Qt::RoundCap));
      }
    }
  }
}

std::vector<Point> &Scene::GetSolvingPoints() noexcept {
  return solving_points_;
}

void Scene::DrawSolving(std::vector<Point> solving_points) {
  if (solving_points.size() > 1UL) {
    double vertical_offset = vertical_wall_size_ / 2.0 + 1.0;
    double horizontal_offset = horizontal_wall_size_ / 2.0 + 1.0;

    for (auto i = 0UL; i < solving_points.size() - 1UL; i++) {
      addLine(
          solving_points[i].col * horizontal_wall_size_ + horizontal_offset,
          solving_points[i].raw * vertical_wall_size_ + vertical_offset,
          solving_points[i + 1UL].col * horizontal_wall_size_ +
              horizontal_offset,
          solving_points[i + 1UL].raw * vertical_wall_size_ + vertical_offset,
          QPen(Qt::green, 2, Qt::SolidLine, Qt::RoundCap));
    }
  }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  if (is_drawn_ && (solving_points_count_ < kSolvingPointsCount)) {
    QPointF scene_pos = event->scenePos();

    solving_points_count_ += 1U;
    SetSolvingPointPositon(scene_pos);
    addEllipse(scene_pos.x() - 5, scene_pos.y() - 5, 10, 10, QPen(Qt::NoPen),
               QBrush(Qt::red));
  }
}

void Scene::SetSolvingPointPositon(QPointF scene_pos) {
  unsigned raw{};
  unsigned col{};
  bool is_not_found{};

  is_not_found = true;
  for (auto i = 0U; (i < raws_) && is_not_found; i++) {
    if (scene_pos.y() < vertical_wall_size_ * (i + 1U)) {
      raw = i;
      is_not_found = false;
    }
  }
  if (is_not_found) {
    raw = raws_ - 1U;
  }

  is_not_found = true;
  for (auto j = 0U; (j < cols_) && is_not_found; j++) {
    if (scene_pos.x() < horizontal_wall_size_ * (j + 1U)) {
      col = j;
      is_not_found = false;
    }
  }
  if (is_not_found) {
    col = cols_ - 1U;
  }

  solving_points_.push_back({raw, col});
}
