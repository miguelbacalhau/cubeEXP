#include "BallObject.h"
#include "../Factory/CubeSphereFactory.h"

/**
 * Constructor
 * instatiates the object and builds its model
 */
BallObject::BallObject() {
    this->buildModel();
}

/**
 * Model create
 */
void BallObject::buildModel() {
    CubeSphereFactory* factory = new CubeSphereFactory(0.01, 100, 100);
    this->setModel(
        factory->makeModel()
    );
}
