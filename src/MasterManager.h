#ifndef INCLUDED_MASTERMANAGER
#define INCLUDED_MASTERMANAGER
#include "Window/Window.h"

class GameObject;

class MasterManager {
    private:
        GameObject* gameObject;
        Window* window;

    public:
        MasterManager();
        void InitializeGlutCallbacks();
        void static RenderSceneCB();
        int glewInitialize();
        int gameGo();
        void key(unsigned char keyCode);
};
#endif
