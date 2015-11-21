#include "CubeObject.h"
#include "../Model/Solid/Cube.h"
#include <stdlib.h>
#include <iostream>
/**
 * Constructor
 * instatiates the object and builds its model
 */
CubeObject::CubeObject(double size) :
    GameObject() {
    this->_size = size;
    this->buildModel();
}

/**
 * Model create
 */
void CubeObject::buildModel() {
    Position position;
    position.x = position.y = position.z = 0.0;
    Color color;
    color.red = (double)(rand() % 100) / 100;
    color.green = (double)(rand() % 100) / 100;
    color.blue = (double)(rand() % 100) / 100;
    Cube* cube = new Cube(this->_size, position, color);
    this->setModel(cube);
}
