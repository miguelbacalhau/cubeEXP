#ifndef INCLUDED_SOLID
#define INCLUDED_SOLID
#include <iostream>
#include "../Visitor/Visited.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class Solid : public Visited {

    private:
        float _positionX, _positionY, _positionZ;
        float color;
    public:
        std::string virtual getName() = 0;
        void virtual accept(Visitor *visitor);
};
#endif
