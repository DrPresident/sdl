#ifndef HERO
#define HERO

#include <SDL2/SDL.h>
#include "../sprite.h"
#include "../anim.h"
#include "../object.h"
#include "../screen.h"

class Hero : public Object{
    public:
        Hero(Screen *s, const char* imgRes = "res/default.png", int x = 0, int y = 0, int w = 32, int h = 32, 
                int numAnims = 0, int r = 1, int c = 1, int speed = 1);

        virtual void update(int);

        void moveLeft(int);
        void moveRight(int);
        void moveUp(int);
        void moveDown(int);

    protected:
        const char* name;
        int numAnims;
};

#endif
