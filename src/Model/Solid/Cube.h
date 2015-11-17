#ifndef INCLUDED_CUBE
#define INCLUDED_CUBE
#include "Solid.h"
#include "../../CommonDataStructures.h"

class Cube : public Solid {

    private:
        /**
         * @var Cube side lenght
         */
        double _sideLenght;

    public:
        /**
         * Constructor
         */
        Cube(double sidesLenght, Position position, Color color);
        /**
         * Getters and Setter
         */
        double getSideLenght();
        double getSizeX();
        double getSizeY();
        double getSizeZ();
        Volume getVolume();

        /**
         * Visitor Pattern
         */
        void accept(Visitor *visitor);
};
#endif
