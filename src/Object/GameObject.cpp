#include "GameObject.h"
#include "../Model/Model.h"
#include <iostream>

GameObject::GameObject() {
    Position position;
    position.x = position.y = position.z = 0;
    this->_position = position;
}
void GameObject::setModel(Model* model) {
    this->_model = model;
    std::cout << "bacalhau" << std::endl;
}
Model* GameObject::getModel() {
    return this->_model;
}

Position GameObject::getPosition() {
    return this->_position;
}

void GameObject::setPosition(Position position) {
    this->_position = position;
    this->_model->setPosition(position);
    std::cout << "x: " << this->_position.x << " y: " << this->_position.y << " z :" << this->_position.z << std::endl;
}

void GameObject::movePosition(Position position) {
    Position finalPosition;
    finalPosition.x = this->_position.x + position.x;
    finalPosition.y = this->_position.y + position.y;
    finalPosition.z = this->_position.z + position.z;
    this->setPosition(finalPosition);
}

void GameObject::moveUp(double units) {
    Position position;
    position.x = position.z = 0;
    position.y = units;
    this->movePosition(position);
}

void GameObject::moveDown(double units) {
    Position position;
    position.x = position.z = 0;
    position.y = - units;
    this->movePosition(position);
}

void GameObject::moveRight(double units) {
    Position position;
    position.y = position.z = 0;
    position.x = units;
    this->movePosition(position);
}

void GameObject::moveLeft(double units) {
    Position position;
    position.y = position.z = 0;
    position.x = - units;
    this->movePosition(position);
}

void GameObject::moveForward(double units) {
    Position position;
    position.x = position.y = 0;
    position.z = - units;
    this->movePosition(position);
}

void GameObject::moveBack(double units) {
    Position position;
    position.x = position.y = 0;
    position.z = units;
    this->movePosition(position);
}
