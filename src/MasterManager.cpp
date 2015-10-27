#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Model/CompModel.h"
#include "Model/Solid/Cube.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"

MasterManager::MasterManager() {
    this->window = new Window();
    Position position;
    Color color;
    position.x = position.y = position.z = 0.0;
    color.red = color.green = color.blue = 0.5;
    Cube *cube1 = new Cube(0.5, position, color);
    position.x = 1.0;
    color.red = color.green = color.blue = 0.3;
    Cube *cube2 = new Cube(0.5, position, color);
    position.x = -1.0;
    color.red = color.green = color.blue = 0.7;
    Cube *cube3 = new Cube(0.5, position, color);
    std::vector<Model*> models;
    models.push_back(cube1);
    models.push_back(cube2);
    models.push_back(cube3);
    position.x = 0.0;
    CompModel* compModel = new CompModel(position, models);
    this->solid = compModel;
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
