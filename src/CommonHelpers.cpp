#include "CommonDataStructures.h"
#include <math.h>
/**
 * Pi value constant
 */
#define PI 3.14

/**
 * Helper function
 * creates a vector with sphere points
 */
std::vector<Position> CommonHelpers::generateSpherePositions(int rings, int points) {
    std::vector<Position> positions;
    Position position;
    position.x = position.y = 0.0; position.z = 1.0;
    positions.push_back(position);

    double pi = PI;
    double deltaTheta = pi / rings;
    double deltaPhi = 2 * pi / points;
    double theta, phi;
    phi = theta = 0;
    for(int ring = 0; ring < rings; ring++){ //move to a new z - offset
        theta += deltaTheta;
        for(int point = 0; point < points; point++){ // draw a ring
            phi += deltaPhi;
            position.x = sin(theta) * cos(phi);
            position.y = sin(theta) * sin(phi);
            position.z = cos(theta);
            positions.push_back(position);
        }
    }

    position.x = position.y = 0.0; position.z = -1.0;
    positions.push_back(position);

    return positions;
}

