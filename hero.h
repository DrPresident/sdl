#ifndef HERO
#define HERO

#include <SDL/SDL.h>
#include "sprite.h"
#include "anim.h"
#include "visible.h"

class Hero : public Visible{
    public:
        Hero(const char* name = "name", const char* imgRes = "res/default.png", 
                int x = 0, int y = 0, int w = 32, int h = 32);

        virtual void update(int);

    protected:
        const char* name;
        int numAnims;
};

typedef void (Hero::*heroFuncPtr)(void);

#endif
