#ifndef INCLUDED_MASTERMANAGER
#define INCLUDED_MASTERMANAGER
#include "Window/Window.h"
#include <vector>

class GameObject;
class Physics;
class Time;

class MasterManager {
    private:
        std::vector<GameObject*>* objects;
        GameObject* gameObject;
        Window* window;
        Physics* physics;
        Time* timeManager;

    public:
        MasterManager();
        void InitializeGlutCallbacks();
        void static RenderSceneCB();
        int glewInitialize();
        void physicsGo();
        int gameGo();
        void key(unsigned char keyCode);
};
#endif
