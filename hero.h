#ifndef HERO
#define HERO

#include <SDL/SDL.h>
#include "sprite.h"
#include "anim.h"
#include "visible.h"

#include <iostream>

class Hero : public Visible{
    public:
        Hero(const char* name = "name", const char* imgRes = "res/default.png", int speed = 1, 
                int x = 0, int y = 0, int w = 32, int h = 32, 
                int numAnims = 0, int r = 1, int c = 1);

        virtual void update(int);

        void moveLeft(int);
        void moveRight(int);
        void moveUp(int);
        void moveDown(int);

    protected:
        const char* name;
        int numAnims;
        int speed;
        int velocityX;
        int velocityY;
};

#endif
