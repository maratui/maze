#include "draw.h"

using namespace s21;

Draw::Draw(QGraphicsScene *graphics_scene) {
  graphics_scene_ = graphics_scene;
  graphics_view_ = new QGraphicsView();
  v_layout_ = new VBoxLayout(kMargins, this);

  v_layout_->addWidget(graphics_view_, 0, Qt::AlignTop);

  graphics_view_->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphics_view_->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  graphics_view_->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
  graphics_view_->setScene(graphics_scene_);

  setContentsMargins(kMargins, kMargins, kMargins, kMargins);
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}
