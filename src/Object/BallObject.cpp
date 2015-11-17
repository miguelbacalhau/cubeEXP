#include "BallObject.h"
#include "../Factory/CubeSphereFactory.h"

/**
 * Constructor
 * instatiates the object and builds its model
 */
BallObject::BallObject(bool movable) :
    GameObject(movable) {
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
