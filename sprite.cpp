#include "sprite.h"

Sprite::Sprite(const char* resource){
    
    sprite = IMG_Load(resource);
    anim = new Animation();
}

bool Sprite::loadSprite(const char* resource){

    SDL_FreeSurface(sprite);
    sprite = IMG_Load(resource);

    return true;
}

void Sprite::update(int dTime){

    anim->update(dTime);
}
