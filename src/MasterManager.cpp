#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Model/Model.h"
#include "Factory/CubeSphereFactory.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"

MasterManager::MasterManager() {
    this->window = new Window();
    CubeSphereFactory* factory = new CubeSphereFactory(0.01, 100, 100);
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
