#include <iostream>
#include "MasterManager.h"
#include "Object/ObjectA.h"

void MasterManager::gameGo() {
    std::cout << "Game started" << std::endl;
    this->object = new ObjectA();
    this->object->doStuff();
}
