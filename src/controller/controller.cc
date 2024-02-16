#include "controller.h"

using namespace s21;

Controller::Controller(Facade *facade) : facade_(facade) {}

Scene *Controller::GetScene() noexcept { return facade_->GetScene(); }

void Controller::ClearScene() { facade_->ClearScene(); }

void Controller::LoadMaze(const std::string &path) { facade_->LoadMaze(path); }

void Controller::GenerateMaze(const std::string &path, unsigned raws,
                              unsigned cols) {
  facade_->GenerateMaze(path, raws, cols);
}

void Controller::DrawMaze() { facade_->DrawMaze(); }

void Controller::SolvMaze() { facade_->SolvMaze(); }
