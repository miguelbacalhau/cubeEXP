#ifndef INCLUDED_SOLID
#define INCLUDED_SOLID
#include <iostream>
#include "../Model.h"

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
        void virtual accept(Visitor *visitor);
};
#endif
