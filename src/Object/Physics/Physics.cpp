#include "Physics.h"
#include "../GameObject.h"
#include "../../Model/Model.h"
#include <iostream>
#include <cmath>

Physics::Physics(std::vector<GameObject*>* objects) {
    this->_objects = objects;
}

void Physics::tick() {
    this->gravity();
    this->calculateForces();
    this->colision();
    this->velocityGoGo();
}

void Physics::gravity() {
    std::vector<GameObject*>* objects = this->_objects;
    GameObject* object;
    for(std::vector<GameObject*>::iterator objectIt = objects->begin(); objectIt != objects->end(); ++objectIt) {
        object = *objectIt;
        if(object->isMovable()) {
            Force force;
            force.x = force.z = 0.0;
            force.y = - 0.01;
            object->addForce(force);
        }
    }
}

void Physics::checkCollision(GameObject* objectA, GameObject* objectB) {
    Model* modelA = objectA->getModel();
    Model* modelB = objectB->getModel();
    Position positionA = objectA->getPosition();
    Position positionB = objectB->getPosition();
    Velocity velocityA = objectA->getVelocity();
    Velocity velocityB = objectB->getVelocity();
    //check the X axis
    if(std::abs(( positionA.x + velocityA.x) - (positionB.x + velocityB.x)) < modelA->getSizeX() + modelB->getSizeX()) {
        //check the Y axis
        if(std::abs(( positionA.y + velocityA.y)- (positionB.y + velocityB.y)) < modelA->getSizeY() + modelB->getSizeY()) {
            //check the Z axis
            if(std::abs(( positionA.z + velocityA.z) - (positionB.z + velocityB.z)) < modelA->getSizeZ() + modelB->getSizeZ()) {
                velocityA.x = velocityB.x = 0.0;
                velocityA.y = velocityB.y = 0.0;
                velocityA.z = velocityB.z = 0.0;
                objectA->setVelocity(velocityA);
                objectB->setVelocity(velocityB);
            }
        }
    }
}

double Physics::colision() {
    std::vector<GameObject*>* objects = this->_objects;
    GameObject *object, *otherObject;
    Velocity velocity, otherVelocity;
    for(std::vector<GameObject*>::iterator objectIt = objects->begin(); objectIt != objects->end(); ++objectIt) {
        object = *objectIt;
        velocity = object->getVelocity();
        for(std::vector<GameObject*>::iterator otherObjectIt = objectIt + 1; otherObjectIt != objects->end(); ++otherObjectIt) {
            otherObject = *otherObjectIt;
            otherVelocity = otherObject->getVelocity();
            this->checkCollision(object, otherObject);
        }
    }

    return 0.0;
}

void Physics::velocityGoGo() {
    std::vector<GameObject*>* objects = this->_objects;
    GameObject* object;
    for(std::vector<GameObject*>::iterator objectIt = objects->begin(); objectIt != objects->end(); ++objectIt) {
        object = *objectIt;
        Velocity velocity = object->getVelocity();
        object->movePosition(velocity);
        Acceleration acceleration = object->getAcceleration();
        velocity.x = velocity.x + acceleration.x;
        velocity.y = velocity.y + acceleration.y;
        velocity.z = velocity.z + acceleration.z;
        object->setVelocity(velocity);
    }
}

void Physics::calculateForces() {
    std::vector<GameObject*>* objects = this->_objects;
    Force force;
    Acceleration acceleration;
    GameObject* object;
    for(std::vector<GameObject*>::iterator objectIt = objects->begin(); objectIt != objects->end(); ++objectIt) {
        object = *objectIt;
        force = object->getForce();
        //acceleration =object->getAcceleration();
        acceleration.x = force.x;
        acceleration.y = force.y;
        acceleration.z = force.z;
        object->setAcceleration(acceleration);
        force.x = force.y = force.z = 0.0;
        object->setForce(force);
    }
}

