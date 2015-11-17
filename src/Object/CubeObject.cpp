#include "CubeObject.h"
#include "../Model/Solid/Cube.h"
/**
 * Constructor
 * instatiates the object and builds its model
 */
CubeObject::CubeObject(bool movable) :
    GameObject(movable) {
    //this->setPosition(position);
    this->buildModel();
}

/**
 * Model create
 */
void CubeObject::buildModel() {
    Position position;
    position.x = position.y = position.z = 0.0;
    Color color;
    color.red = color.green = 0.0;
    color.blue = 0.6;
    Cube* cube = new Cube(0.5, position, color);
    this->setModel(cube);
}
