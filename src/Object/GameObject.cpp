#include "GameObject.h"
#include "../Model/Model.h"
#include <iostream>

/**
 * Constructor
 */
GameObject::GameObject(bool movable) {
    Position position;
    position.x = position.y = position.z = 0;
    this->_position = position;
    this->_movable = movable;
}

/**
 * Getters & Setters
 */
void GameObject::setModel(Model* model) {
    this->_model = model;
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
}

Velocity GameObject::getVelocity() {
    return this->_velocity;
}

void GameObject::setVelocity(Velocity velocity) {
    this->_velocity = velocity;
}

bool GameObject::isMovable() {
    return this->_movable;
}
void GameObject::setMovable(bool movable) {
    this->_movable = movable;
}

/**
 * Movement
 */
void GameObject::movePosition(Velocity velocity) {
    Position finalPosition;
    finalPosition.x = this->_position.x + velocity.x;
    finalPosition.y = this->_position.y + velocity.y;
    finalPosition.z = this->_position.z + velocity.z;
    this->setPosition(finalPosition);
}

void GameObject::moveUp(double units) {
    Velocity velocity;
    velocity.x = velocity.z = 0;
    velocity.y = units;
    this->movePosition(velocity);
}

void GameObject::moveDown(double units) {
    Velocity velocity;
    velocity.x = velocity.z = 0;
    velocity.y = - units;
    this->movePosition(velocity);
}

void GameObject::moveRight(double units) {
    Velocity velocity;
    velocity.y = velocity.z = 0;
    velocity.x = units;
    this->movePosition(velocity);
}

void GameObject::moveLeft(double units) {
    Velocity velocity;
    velocity.y = velocity.z = 0;
    velocity.x = - units;
    this->movePosition(velocity);
}

void GameObject::moveForward(double units) {
    Velocity velocity;
    velocity.x = velocity.y = 0;
    velocity.z = - units;
    this->movePosition(velocity);
}

void GameObject::moveBack(double units) {
    Velocity velocity;
    velocity.x = velocity.y = 0;
    velocity.z = units;
    this->movePosition(velocity);
}
