#ifndef CONTROLS
#define CONTROLS

#include <SDL/SDL.h>
#include "anim.h"
#include "hero.h"

class Controls{
    public:
        Controls();
        void updateInput();

        void setInput(int input, heroFuncPtr callback, Animation* anim);

    private:

        heroFuncPtr* controlCallbacks;
        Animation** animCallbacks;
        Hero *character;
};

#endif
