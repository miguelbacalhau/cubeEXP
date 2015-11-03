#include <iostream>
#include "../CommonDataStructures.h"
#include "CubeSphereFactory.h"
#include "../Model/Solid/Cube.h"
#include "../Model/CompositeModel.h"

/**
 * Constructor
 */
CubeSphereFactory::CubeSphereFactory(double size, int rings, int points) {
    this->_size = size;
    this->_rings = rings;
    this->_points = points;
}

/**
 * Setters
 */
void CubeSphereFactory::setSize(double size) {
    this->_size = size;
}

void CubeSphereFactory::setRings(int rings) {
    this->_rings = rings;
}

void CubeSphereFactory::setPoints(int points) {
    this->_points = points;
}

/**
 * Model Factory override
 * creates a Sphere made out of cubes Model
 */
Model* CubeSphereFactory::makeModel() {
    std::vector<Position> positions;
    positions = CommonHelpers::generateSpherePositions(this->_rings, this->_points);

    Position position;
    Color color;
    color.green = color.blue = 0.0;
    color.red = 0.6;
    std::vector<Model*> models;
    for(std::vector<Position>::iterator positionIt = positions.begin(); positionIt != positions.end(); ++positionIt) {
        position = *positionIt;
        models.push_back(
            new Cube(this->_size, position, color)
        );
    }
    position.x = position.y = position.z = 0.0;
    return new CompositeModel(position, models);

}
