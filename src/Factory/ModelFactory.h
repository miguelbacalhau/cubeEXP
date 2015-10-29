#ifndef INCLUDED_MODELFACTORY
#define INCLUDED_MODELFACTORY

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Model;

class ModelFactory {

    public:
        virtual Model* makeModel() = 0;
};
#endif
