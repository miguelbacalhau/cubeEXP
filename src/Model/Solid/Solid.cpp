#include "Solid.h"
#include "../../Visitor/Visitor.h"

/**
 * Constructure
 */
Solid::Solid(Position position, Color color)
    : Model(position){
    this->_color.red = color.red;
    this->_color.green = color.green;
    this->_color.blue = color.blue;
}

/**
 * Getters & Setters
 */
Color Solid::getColor() {
    return this->_color;
}

/**
 * Visitor Pattern accept
 */
void Solid::accept(Visitor *visitor) {
    visitor->visit(this);
}
