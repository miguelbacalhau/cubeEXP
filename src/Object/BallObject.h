#ifndef INCLUDED_BALLOBJECT
#define INCLUDED_BALLOBJECT

#include "GameObject.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */

class BallObject : public GameObject{

    public:
        /**
         * Constructor
         */
        BallObject(bool movable);

        /**
         * Builds desired model
         */
        void buildModel();
};
#endif
