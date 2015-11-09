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
        Velocity velocity;
        bool _movable;
        // TODO animation?

    public:
        /**
         * Constructor
         */
        GameObject();

        /**
         * Getters & Setters
         */
        Model* getModel();
        void setModel(Model* model);
        Position getPosition();
        void setPosition(Position position);
        bool isMovable();
        /**
         * Movement
         */
        void movePosition(Position position);
        void moveUp(double units);
        void moveDown(double units);
        void moveRight(double units);
        void moveLeft(double units);
        void moveForward(double units);
        void moveBack(double units);

        /**
         * Builds the desired Model
         */
        virtual void buildModel() = 0;
};
#endif
