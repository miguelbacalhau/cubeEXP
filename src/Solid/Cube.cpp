#include <iostream>
#include "Cube.h"
#include "../Visitor/Visitor.h"

Cube::Cube(double sidesLenght) {
    this->_sideLenght = sidesLenght;
}
/**
 * Getters & Setters
 */
std::string Cube::getName() {
    return "I am Cube";
}
double Cube::getSideLenght() {
    return this->_sideLenght;
}

/**
 * @Override
 */
void Cube::accept(Visitor *visitor) {
    visitor->visit(this);
}
