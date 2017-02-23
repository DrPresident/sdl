#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cassert>
#include "anim.h"
#include "object.h"

class Sprite : public Object{
    public:
        Sprite();
        Sprite(SDL_Renderer *render, const char* resource, int numAnims = 0, int r = 1, int c = 1);
        bool loadSprite(const char*);
        
        SDL_Rect* getRect();
        SDL_Texture* getTexture();

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;

        friend class Animation;
};

#endif
