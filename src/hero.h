#ifndef HERO
#define HERO

#include <SDL2/SDL.h>
#include "sprite.h"
#include "anim.h"
#include "object.h"

class Hero : public Object{
    public:
        Hero(int x = 0, int y = 0, int w = 32, int h = 32, 
                int numAnims = 0, int r = 1, int c = 1, 
                const char* imgRes = "res/default.png", int speed = 1);

        virtual void update(int);

        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

    protected:
        const char* name;
        int numAnims;

};

#endif
