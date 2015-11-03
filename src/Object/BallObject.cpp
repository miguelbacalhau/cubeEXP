#include "BallObject.h"
#include "../Factory/CubeSphereFactory.h"

BallObject::BallObject() {
    this->buildModel();
}

void BallObject::buildModel() {
    CubeSphereFactory* factory = new CubeSphereFactory(0.01, 100, 100);
    this->setModel(
        factory->makeModel()
    );
}
