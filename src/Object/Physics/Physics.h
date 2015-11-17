#ifndef INCLUDED_PHYSICS
#define INCLUDED_PHYSICS
#include <vector>

#define GRAVITY_UNITS 0.01

/**
 * forward declarations of classes
 * (avoids circular dependencies)
 */
class GameObject;

class Physics {

    private:
        std::vector<GameObject*>* _objects;

    public:
        Physics(std::vector<GameObject*>* objects);
        void tick();

    private:
        void gravity();
        double colision();
        void checkCollision(GameObject* a, GameObject* b);
        void velocityGoGo();
};
#endif
