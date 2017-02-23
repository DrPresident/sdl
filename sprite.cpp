#include "sprite.h"

Sprite::Sprite(){

    texture = NULL;
    renderer = NULL;
}

Sprite::Sprite(SDL_Renderer *render, const char* resource){
    
    texture = NULL;
    renderer = render;
    loadSprite(resource);
    
    curAnim = 0;
    rows = r;
    cols = c;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

bool Sprite::loadSprite(const char* resource){

    if(texture)
        SDL_DestroyTexture(texture);

    SDL_Surface *s = IMG_Load(resource);
    texture = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    return true;
}

SDL_Rect* Sprite::getRect(){
     
    return NULL; 
}

SDL_Texture* Sprite::getTexture(){
    return texture;
}
