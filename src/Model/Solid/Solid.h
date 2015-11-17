#ifndef INCLUDED_SOLID
#define INCLUDED_SOLID
#include <iostream>
#include "../Model.h"
#include "../../CommonDataStructures.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class Solid : public Model {

    private:
        Color _color;
    public:
        Solid(Position position, Color color);
        Color getColor();
        virtual double getSizeX() = 0;
        virtual double getSizeY() = 0;
        virtual double getSizeZ() = 0;
        virtual Volume getVolume() = 0;
        virtual void accept(Visitor *visitor);
};
#endif
