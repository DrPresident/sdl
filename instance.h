#include <SDL/SDL.h>
#include <vector>
#ifndef INSTANCE
#define INSTANCE

#include <algorithm>
#include "screen.h"
#include "controls.h"

class Instance{
    public:
        void run();
        void updateScreens(int);

        void addScreen(Screen& scr){ screens.push_back(&scr); }
        void removeScreen(Screen&);
    private:
    
        std::vector<Screen*> screens;
};

#endif
