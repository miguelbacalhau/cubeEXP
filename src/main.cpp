#include <iostream>
#include "MasterManager.h"

int main() {
    std::cout << "Engine Engaged" << std::endl;
    MasterManager* master = new MasterManager();
    master->gameGo();
}
