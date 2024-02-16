QT          += widgets

CONFIG      += c++17

INCLUDEPATH += \
  model \
  facade \
  controller \
  view

SOURCES     += \
  ../model/set_maze.cc \
  ../model/generate_maze.cc \
  ../model/solv_maze.cc \
  ../facade/file_reader.cc \
  ../facade/scene.cc \
  ../facade/facade.cc \
  ../controller/controller.cc \
  ../view/layout.cc \
  ../view/button.cc \
  ../view/draw.cc \
  ../view/view.cc \
  ../view/main.cc

HEADERS     += \
  ../model/point.h \
  ../model/maze.h \
  ../facade/file_reader.h \
  ../facade/scene.h \
  ../facade/facade.h \
  ../controller/controller.h \
  ../view/layout.h \
  ../view/button.h \
  ../view/draw.h \
  ../view/view.h
