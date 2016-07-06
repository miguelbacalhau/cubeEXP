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
        Velocity _velocity;
        Acceleration _acceleration;
        Force _force;
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
        Velocity getVelocity();
        void setVelocity(Velocity velocity);
        Acceleration getAcceleration();
        void setAcceleration(Acceleration acceleration);
        bool isMovable();
        void setMovable(bool movable);
        Force getForce();
        void setForce(Force force);

        /**
         * Adds a new Force to the Object
         */
        void addForce(Force force);

        /**
         * Movement
         */
        void movePosition(double time);

        /**
         * Builds the desired Model
         */
        virtual void buildModel() = 0;
};
#endif
