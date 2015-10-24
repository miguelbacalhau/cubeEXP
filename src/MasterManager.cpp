#include <iostream>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Solid/Cube.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"

MasterManager::MasterManager() {
    this->window = new Window();
    this->solid = new Cube(1.0);
}

void MasterManager::InitializeGlutCallbacks() {
}

void MasterManager::RenderSceneCB() {
}

int MasterManager::glewInitialize() {
    return 0;
}

int MasterManager::gameGo() {
    DrawVisitor *drawVisitor = new DrawVisitor();
    this->solid->accept(drawVisitor);

    return 0;
}
