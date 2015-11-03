#ifndef INCLUDED_CUBESPHEREFACTORY
#define INCLUDED_CUBESPHEREFACTORY
#include "ModelFactory.h"

class CubeSphereFactory : public ModelFactory {

    private:
        double _size, _rings, _points;
    public:
        CubeSphereFactory(double size, int rings, int points);
        void setSize(double size);
        void setRings(int rings);
        void setPoints(int points);
        Model* makeModel();
};
#endif
