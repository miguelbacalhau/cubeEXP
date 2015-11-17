#include <iostream>
#include "Cube.h"
#include "../../Visitor/Visitor.h"

/**
 * Constructor
 */
Cube::Cube(double sidesLenght, Position position, Color color)
    :Solid(position, color) {
    this->_sideLenght = sidesLenght;
}

/**
 * Getters & Setters
 */
double Cube::getSideLenght() {
    return this->_sideLenght;
}
double Cube::getSizeX() {
    return this->_sideLenght/2;
}
double Cube::getSizeY() {
    return this->_sideLenght/2;
}
double Cube::getSizeZ() {
    return this->_sideLenght/2;
}
Volume Cube::getVolume() {
    Position position = this->getPosition();
    Volume volume;
    volume.maxX = volume.maxY = volume.maxZ = this->_sideLenght / 2;
    volume.minX = volume.minY = volume.minZ = - this->_sideLenght / 2;
    volume.minX += position.x;
    volume.maxX += position.x;
    volume.minY += position.y;
    volume.maxY += position.y;
    volume.minZ += position.z;
    volume.maxZ += position.z;
    return volume;
}

/**
 * Visitor Pattern accept
 * @Override
 */
void Cube::accept(Visitor *visitor) {
    visitor->visit(this);
}
