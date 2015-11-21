#include "GameObject.h"
#include "../Model/Model.h"
#include <iostream>

/**
 * Constructor
 */
GameObject::GameObject() {
    Position position;
    position.x = position.y = position.z = 0.0;
    Velocity velocity;
    velocity.x = velocity.y = velocity.z = 0.0;
    Acceleration acceleration;
    acceleration.x = acceleration.y = acceleration.z = 0.0;
    Force force;
    force.x = force.y = force.z = 0.0;
    this->_position = position;
    this->_velocity = velocity;
    this->_acceleration = acceleration;
    this->_movable = true;
    this->_force = force;
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

Acceleration GameObject::getAcceleration() {
    return this->_acceleration;
}

void GameObject::setAcceleration(Acceleration acceleration) {
    this->_acceleration = acceleration;
}

bool GameObject::isMovable() {
    return this->_movable;
}
void GameObject::setMovable(bool movable) {
    this->_movable = movable;
}

Force GameObject::getForce() {
    return this->_force;
}

void GameObject::setForce(Force force) {
    this->_force = force;
}

void GameObject::addForce(Force force) {
    this->_force += force;
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
