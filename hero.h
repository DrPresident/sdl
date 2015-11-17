#ifndef HERO
#define HERO

#include <SDL/SDL.h>
#include "sprite.h"
#include "anim.h"
#include "visible.h"

class Hero : public Visible{
    public:
        Hero(const char* name = "name", const char* imgRes = "res/default.png", int x = 0, int y = 0);

    private:
        const char* name;
        int x;
        int y;
        int numAnims;
};

#endif
