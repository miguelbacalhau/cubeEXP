#ifndef INCLUDED_MODEL
#define INCLUDED_MODEL
#include "../CommonDataStructures.h"
#include "../Visitor/Visited.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Visitor;

class Model : public Visited {

    private:
        Position _position;
    public:
        Model(Position position);
        Position getPosition();
        void setPosition(Position position);
        virtual Volume getVolume() = 0;
        virtual double getSizeX() = 0;
        virtual double getSizeY() = 0;
        virtual double getSizeZ() = 0;
        virtual void accept(Visitor *visitor) = 0;
};
#endif
