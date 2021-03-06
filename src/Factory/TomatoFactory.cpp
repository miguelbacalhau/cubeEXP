#include <iostream>
#include <cstdlib>
#include <math.h>
#include "../CommonDataStructures.h"
#include "TomatoFactory.h"
#include "../Model/Solid/Cube.h"
#include "../Model/CompositeModel.h"

/**
 * Constructure
 */
TomatoFactory::TomatoFactory(double size) {
    this->_size = size;
}

/**
 * Setter
 */
void TomatoFactory::setSize(double size) {
    this->_size = size;
}

Model* TomatoFactory::makeModel() {
    std::vector<Position> positions = CommonHelpers::generateSpherePositions(25, 25);
    Position position;
    Color color;
    color.green = color.blue = 0.0;
    color.red = 0.6;
    std::vector<Model*> models;
    for(std::vector<Position>::iterator positionIt = positions.begin(); positionIt != positions.end(); ++positionIt) {
        position.x = positionIt->x;
        position.y = positionIt->y;
        position.z = positionIt->z;
        models.push_back(
            new Cube(this->_size, position, color)
        );
    }
    position.x = position.y = position.z = 0.0;
    return new CompositeModel(position, models);

}
