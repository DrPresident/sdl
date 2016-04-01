#include "object.h"

#define CORRECTION 1

Object::Object(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    parent = NULL;
}

Object::Object(int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    parent = NULL;
}

Object::Object(Object *parent){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    this->parent = parent;
}

Object::Object(Object *parent, int x, int y, int w, int h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    this->parent = parent;
}

bool Object::attachTo(Object *par){
    if(par != this){
        parent = par;
        return true;
    }
    return false;
}

bool Object::attachChild(Object *child){
    if(child != this){
        children.push_back(child);
        child->attachTo(this);
        return true;
    }
    return false;
}

int Object::getX(){ return x; }
int Object::getY(){ return y; }
int Object::getWidth(){ return w; }
int Object::getHeight(){ return h; }

void Object::setX(int x){ this->x = x; }
void Object::setY(int y){ this->y = y; }
void Object::setWidth(int w){ this->w = w; }
void Object::setHeight(int h){ this->h = h; }

void Object::update(int dTime){
    x += velocityX * dTime;
    y += velocityY * dTime;
}
