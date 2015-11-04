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
void MasterManager::key(unsigned char keyCode) {
    switch (keyCode) {
        case 'd':
            this->gameObject->moveRight(VELOCITY);
            break;
        case 'a':
            this->gameObject->moveLeft(VELOCITY);
            break;
        case 'w':
            this->gameObject->moveUp(VELOCITY);
            break;
        case 's':
            this->gameObject->moveDown(VELOCITY);
            break;
        case 'j':
            this->gameObject->moveForward(VELOCITY);
            break;
        case 'k':
            this->gameObject->moveBack(VELOCITY);
            break;
    }
}
