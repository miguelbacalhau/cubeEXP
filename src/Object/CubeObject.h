#ifndef INCLUDED_CUBEOBJECT
#define INCLUDED_CUBEOBJECT

#include "GameObject.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */

class CubeObject : public GameObject{

    public:
        /**
         * Constructor
         */
        CubeObject(bool movable);

        /**
         * Builds desired model
         */
        void buildModel();
};
#endif
