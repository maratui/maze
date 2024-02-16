#ifndef A1_MAZE_VIEW_DRAW_H_
#define A1_MAZE_VIEW_DRAW_H_

#include <QGraphicsView>
#include <QWidget>

#include "layout.h"

namespace s21 {
class Draw : public QWidget {
  Q_OBJECT

 public:
  Draw() = delete;
  explicit Draw(QGraphicsScene *graphics_scene);

 private:
  const unsigned kMargins = 3U;

  QGraphicsScene *graphics_scene_{};
  QGraphicsView *graphics_view_{};
  VBoxLayout *v_layout_{};
};
}  // namespace s21

#endif  // A1_MAZE_VIEW_DRAW_H_
