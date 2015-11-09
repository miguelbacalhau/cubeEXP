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
        void gravity(GameObject* object);
        void velocityGoGo(GameObject* object);
};
#endif
