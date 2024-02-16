#include "layout.h"

using namespace s21;

GridLayout::GridLayout(const unsigned margins, QWidget *parent)
    : QGridLayout(parent) {
  setContentsMargins(margins, margins, margins, margins);
  setSpacing(0);
}

VBoxLayout::VBoxLayout(const unsigned margins, QWidget *parent)
    : QVBoxLayout(parent) {
  setContentsMargins(margins, margins, margins, margins);
  setSpacing(3);
}

HBoxLayout::HBoxLayout(const unsigned margins, QWidget *parent)
    : QHBoxLayout(parent) {
  setContentsMargins(margins, margins, margins, margins);
  setSpacing(0);
}
