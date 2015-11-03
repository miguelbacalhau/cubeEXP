#include "Model.h"

/**
 * Constructure
 */
Model::Model(Position position){
    this->_position.x = position.x;
    this->_position.y = position.y;
    this->_position.z = position.z;
}

/**
 * Getters & Setters
 */
Position Model::getPosition() {
    return this->_position;
}

void Model::setPosition(Position position) {
    this->_position = position;
}
