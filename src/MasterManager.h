#ifndef INCLUDED_MASTERMANAGER
#define INCLUDED_MASTERMANAGER
#include "Window/Window.h"

class Solid;

class MasterManager {
    private:
        Solid* solid;
        Window* window;

    public:
        MasterManager();
        void InitializeGlutCallbacks();
        void static RenderSceneCB();
        int glewInitialize();
        int gameGo();
};
#endif
