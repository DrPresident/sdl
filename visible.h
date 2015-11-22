#ifndef VISIBLE
#define VISIBLE

#include "object.h"
#include "sprite.h"

class Visible : public Object{
    public:
        SDL_Rect* getRect(){ return sprite->getRect(); }
        SDL_Surface* getSprite(){ return sprite->getSprite(); } 
        virtual void update(int) = 0;

    protected:
        Sprite *sprite;

};

#endif
