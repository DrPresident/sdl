#include "hero.h"

Hero::Hero(const char* name, const char* imgRes, int x, int y, int w, int h){
    
    this->name = name;
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;

    sprite = new Sprite(imgRes);
}

void Hero::update(int dTime){

    sprite->update(dTime);
}
