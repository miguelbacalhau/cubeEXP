#include "Physics.h"
#include "../GameObject.h"

Physics::Physics(std::vector<GameObject*>* objects) {
    this->_objects = objects;
}

void Physics::tick() {
    std::vector<GameObject*>* objects = this->_objects;
    GameObject* object;
    for(std::vector<GameObject*>::iterator objectIt = objects->begin(); objectIt != objects->end(); ++objectIt) {
        object = *objectIt;
        this->gravity(object);
        this->velocityGoGo(object);
    }
}

void Physics::gravity(GameObject* object) {
    if(object->isMovable()) {
        object->moveDown(GRAVITY_UNITS);
    }
}

void Physics::velocityGoGo(GameObject* object) {

}
