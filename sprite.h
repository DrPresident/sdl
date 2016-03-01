#ifndef SPRITE
#define SPRITE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include <cassert>
#include "object.h"
#include "anim.h"

#include <iostream>

class Animation;

class Sprite : public Object{
    public:
        Sprite(const char* resource, int numAnims = 0, int r = 1, int c = 1);
        bool loadSprite(const char*);

        void update(int);
        
        SDL_Rect* getRect();
        SDL_Surface* getSurface();

        void play();
        void start();
        void stop();

        int getNumAnims();
        int addAnim(int startFrame, int frames, int msDelay);
        void setAnim(int);

    private:
        SDL_Surface* surface;
        std::vector<Animation> anims;

        int curAnim;
        int rows;
        int cols;

        friend class Animation;
};

#endif
