#include "sprite.h"

Sprite::Sprite(const char* resource){
    
    sprite = SDL_LoadBMP(resource);
    anim = new Animation();
}
