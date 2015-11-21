#ifndef INCLUDED_CUBEOBJECT
#define INCLUDED_CUBEOBJECT

#include "GameObject.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */

class CubeObject : public GameObject{

    private:
        double _size;
    public:
        /**
         * Constructor
         */
        CubeObject(double size);

        /**
         * Builds desired model
         */
        void buildModel();
};
#endif
