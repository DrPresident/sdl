#ifndef SPRITE
#define SPRITE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "object.h"
#include "anim.h"

class Sprite : public Object{
    public:
        Sprite(const char*);
        bool loadSprite(const char*);

        void update(int);
        
        SDL_Rect* getRect(){ return anim->getFrame(); } 
        SDL_Surface* getSprite(){ return sprite; }

    private:
        SDL_Surface* sprite;
        Animation *anim;

        bool isAnimated;

};

#endif
