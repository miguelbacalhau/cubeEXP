#include <iostream>
#include <CommonDataStructures.h>
#include "TomatoFactory.h"
#include "../Model/CompositeModel.h"
#include "../Model/Solid/Cube.h"

Model* TomatoFactory::makeModel() {
    Position position[8];
    double distance[] = { 0.26, 0.26, 0.26 };
    for (int i = 0; i < 8; i++) {
        if (i > 5) {
            distance[1] *= -1;
            if ( i > 6) {
                distance[0] = distance[2] *= -1;
            }
        } else {
            distance[i % 3] *= -1;
        }

        position[i].x = distance[0];
        position[i].y = distance[1];
        position[i].z = distance[2];
    }

    Color color;
    color.green = color.blue = 0.0;
    color.red = 0.1;

    std::vector<Model*> models;
    for (int i = 0; i < 8 ; i++) {
        color.red += + 0.05 * i;
        models.push_back(
                new Cube(0.5, position[i], color)
                );
    }
    position[0].x = position[0].y = position[0].z = 0.0;
    return new CompositeModel(position[0], models);

}
