#include "sprite.h"

Sprite::Sprite(const char* resource, int numAnims = 0, int r = 1, int c = 1){
    
    sprite = IMG_Load(resource);
    curAnim = 0;
}

bool Sprite::loadSprite(const char* resource){

    SDL_FreeSurface(sprite);
    sprite = IMG_Load(resource);

    return true;
}

void Sprite::update(int dTime){

    anims[curAnim]->update(dTime);
}

int addAnim(int startFrame, int frames, msDelay){

    anims.push_back(Animation(this, rows, cols, startFrame, frames, msDelay); 

    return anims.size() - 1;
}
