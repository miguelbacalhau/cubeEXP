#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Model/Model.h"
#include "Factory/TomatoFactory.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"

MasterManager::MasterManager() {
    this->window = new Window();
    TomatoFactory* factory = new TomatoFactory();
    this->solid = factory->makeModel();
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
