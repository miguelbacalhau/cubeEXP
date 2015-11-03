#ifndef INCLUDED_GAMEOBJECT
#define INCLUDED_GAMEOBJECT

#include "../CommonDataStructures.h"

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class Model;

class GameObject {

    private:
        Model* _model;
        Position _position;
        // TODO animation?

    public:
        GameObject();
        Model* getModel();
        void setModel(Model* model);
        Position getPosition();
        void setPosition(Position position);
        void movePosition(Position position);
        virtual void buildModel() = 0;
};
#endif
