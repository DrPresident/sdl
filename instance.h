#include <SDL/SDL.h>
#include <vector>
#ifndef INSTANCE
#define INSTANCE

#include <algorithm>
#include "screen.h"
#include "hero.h"
#include "controls.h"

class Hero;

class Instance{
    public:

        void run();
        void updateScreens(int);

        void addScreen(Screen& scr){ screens.push_back(&scr); }
        void removeScreen(Screen&);
    private:
    
        std::vector<Screen*> screens;
        Hero* player;
        Controls* playerControls;

};

#endif
