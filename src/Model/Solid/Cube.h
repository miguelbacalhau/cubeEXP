#ifndef INCLUDED_CUBE
#define INCLUDED_CUBE
#include "Solid.h"

class Cube : public Solid {

    private:
        double _sideLenght;
    public:
        Cube(double sidesLenght, Position position, Color color);
        double getSideLenght();
        void accept(Visitor *visitor);
};
#endif
