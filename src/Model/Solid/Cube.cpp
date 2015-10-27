#include <iostream>
#include "Cube.h"
#include "../../Visitor/Visitor.h"

/**
 * Constructure
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

/**
 * Visitor Pattern accept
 * @Override
 */
void Cube::accept(Visitor *visitor) {
    visitor->visit(this);
}
