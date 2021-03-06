#include <iostream>
#include <vector>
#include <GL/freeglut.h>
#include "MasterManager.h"
#include "Object/CubeObject.h"
#include "Object/Physics/Physics.h"
#include "Model/Model.h"
#include "Factory/CubeSphereFactory.h"
#include "Visitor/Visitor.h"
#include "Visitor/DrawVisitor.h"
#include "Window/Window.h"
#include "Manager/Time.h"

#define VELOCITY 0.01

MasterManager::MasterManager() {
    this->window = new Window();
    this->objects = new std::vector<GameObject*>();
    Position position;
    position.x = position.y = position.z = 0.0;
    this->gameObject = new CubeObject(0.5);
    this->gameObject->setMovable(false);
    this->gameObject->setPosition(position);
    this->objects->push_back(this->gameObject);
    position.y = -2.0;
    this->gameObject = new CubeObject(3.0);
    this->gameObject->setMovable(false);
    this->gameObject->setPosition(position);
    this->objects->push_back(this->gameObject);
    position.y = 1.0;
    this->gameObject = new CubeObject(0.5);
    this->gameObject->setPosition(position);
    this->objects->push_back(this->gameObject);
    this->physics = new Physics(this->objects);
    this->timeManager = new Time();
}

void MasterManager::InitializeGlutCallbacks() {
}

void MasterManager::RenderSceneCB() {
}

int MasterManager::glewInitialize() {
    return 0;
}
void MasterManager::physicsGo(){
    this->physics->tick(this->timeManager->getElapsedTime());
}

int MasterManager::gameGo() {
    DrawVisitor *drawVisitor = new DrawVisitor();
    GameObject* object;
    for(std::vector<GameObject*>::iterator objectIt = this->objects->begin(); objectIt != this->objects->end(); ++objectIt) {
        object = *objectIt;
        object->getModel()->accept(drawVisitor);
    }
    //Velocity velocity = this->gameObject->getVelocity();
    //std::cout << "x: " << velocity.x << " y: " << velocity.y << " z: " << velocity.z << std::endl;

    return 0;
}
void MasterManager::key(unsigned char keyCode) {
    Velocity velocity = this->gameObject->getVelocity();
    Force force;
    Position position;
    switch (keyCode) {
        case 'c':
            force.x = 0.0;
            force.y = 0.1;
            force.z = 0.0;
            this->gameObject->addForce(force);
            break;
        case 'g':
            position.x = 0.0;
            position.y = 1.0;
            position.z = 0.0;
            this->gameObject->setPosition(position);
            break;
        case 'f':
            position.x = 1.0;
            position.y = 1.0;
            position.z = 0.0;
            this->gameObject->setPosition(position);
            velocity.x = 0.0;
            velocity.y = 0.0;
            velocity.z = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 'd':
            velocity.x = VELOCITY;
            velocity.y = 0.0;
            velocity.z = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 'a':
            velocity.x = - VELOCITY;
            velocity.y = 0.0;
            velocity.z = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 'w':
            velocity.y = VELOCITY;
            velocity.x = 0.0;
            velocity.z = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 's':
            velocity.y = - VELOCITY;
            velocity.x = 0.0;
            velocity.z = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 'j':
            velocity.z = VELOCITY;
            velocity.y = 0.0;
            velocity.x = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
        case 'k':
            velocity.z = - VELOCITY;
            velocity.y = 0.0;
            velocity.x = 0.0;
            this->gameObject->setVelocity(velocity);
            break;
    }
}
