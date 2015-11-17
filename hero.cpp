#include "hero.h"

Hero::Hero(const char* name, const char* imgRes, int x, int y){
    
    this->name = name;
    this->x = x;
    this->y = y;

    sprite = new Sprite(imgRes);
}
