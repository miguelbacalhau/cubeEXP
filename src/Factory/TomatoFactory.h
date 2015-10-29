#ifndef INCLUDED_TOMATOFACTORY
#define INCLUDED_TOMATOFACTORY
#include "ModelFactory.h"
/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */

class TomatoFactory : public ModelFactory {

    public:
        Model* makeModel();
};
#endif
