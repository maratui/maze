#ifndef A1_MAZE_VIEW_BUTTON_H_
#define A1_MAZE_VIEW_BUTTON_H_

#include <QPushButton>

namespace s21 {
class Button : public QPushButton {
  Q_OBJECT

 public:
  Button() = delete;
  Button(const QString &text, const bool is_width_fixed);

  QSize sizeHint() const override;

 private:
  const unsigned kMargins = 3U;
};
}  // namespace s21

#endif  // A1_MAZE_VIEW_BUTTON_H_
