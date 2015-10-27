#ifndef INCLUDED_MASTERMANAGER
#define INCLUDED_MASTERMANAGER
#include "Window/Window.h"

class Model;

class MasterManager {
    private:
        Model* solid;
        Window* window;

    public:
        MasterManager();
        void InitializeGlutCallbacks();
        void static RenderSceneCB();
        int glewInitialize();
        int gameGo();
};
#endif
