#ifndef INCLUDED_TOMATOFACTORY
#define INCLUDED_TOMATOFACTORY
#include "ModelFactory.h"
/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */

class TomatoFactory : public ModelFactory {

    private:
        double _size;
    public:
        TomatoFactory(double size);
        void setSize(double size);
        Model* makeModel();
};
#endif
