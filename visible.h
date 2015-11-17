#ifndef VISIBLE
#define VISIBLE

#include "object.h"
#include "sprite.h"

class Visible : public Object{
    public:
        SDL_Rect* getRect(){ return sprite->getRect(); }
        SDL_Surface* getSprite(){ return sprite->getSprite(); } 

    protected:
        Sprite *sprite;

};

#endif
