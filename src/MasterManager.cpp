#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Object/BallObject.h"
#include "Model/Model.h"
#include "Factory/CubeSphereFactory.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"

#define VELOCITY 0.1

MasterManager::MasterManager() {
    this->window = new Window();
    //CubeSphereFactory* factory = new CubeSphereFactory(0.01, 100, 100);
    this->gameObject = new BallObject();
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
    this->gameObject->getModel()->accept(drawVisitor);

    return 0;
}
void MasterManager::key(int keyCode) {
    Position position;
    position.x = position.y = position.z = 0.0;
    switch (keyCode) {
        case 65:
            position.x = - VELOCITY;
            break;
        case 68:
            position.x = VELOCITY;
            break;
        case 87:
            position.y = VELOCITY;
            break;
        case 83:
            position.y = - VELOCITY;
            break;
    }
    this->gameObject->movePosition(position);
}
