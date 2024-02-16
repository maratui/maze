#ifndef A1_MAZE_FACADE_SCENE_H_
#define A1_MAZE_FACADE_SCENE_H_

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <vector>

#include "../model/point.h"

namespace s21 {
class Scene : public QGraphicsScene {
  Q_OBJECT

 public:
  Scene();

  void ClearScene();
  void DrawMaze(const std::vector<std::vector<unsigned>> &vertical_walls,
                const std::vector<std::vector<unsigned>> &horizontal_walls);
  std::vector<Point> &GetSolvingPoints() noexcept;
  void DrawSolving(std::vector<Point> solving_points);

 private:
  const unsigned kSceneWidth = 500U;
  const unsigned kSceneHeight = 500U;
  const unsigned kSolvingPointsCount = 2U;

  void DrawVericalHorizontalWalls(
      const std::vector<std::vector<unsigned>> &vertical_walls,
      const std::vector<std::vector<unsigned>> &horizontal_walls);
  void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
  void SetSolvingPointPositon(QPointF scene_position);

  unsigned raws_{};
  unsigned cols_{};
  double vertical_wall_size_{};
  double horizontal_wall_size_{};
  bool is_drawn_{};

  std::vector<Point> solving_points_;
  unsigned solving_points_count_{};
};
}  // namespace s21

#endif  // A1_MAZE_FACADE_SCENE_H_
