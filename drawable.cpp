#include "drawable.h"

SDL_Rect* Drawable::getRect(){
    return sprite.getRect();
}

Sprite Drawable::getSprite(){
    return sprite;
}

void Drawable::update(int dTime){
    Object::update(dTime);
}
