#include "object.h"

#define CORRECTION 1

Object::Object(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
    hit = 0x0;
    correction = 0;
    collider = true;
    reactive = false;
    sprite = NULL;
    col = NULL;
}

Object::Object(int x, int y, int w, int h, bool collider, bool reactive, Sprite* s){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
    hit = 0x0;
    this->collider = collider;
    this->reactive = reactive;
    sprite = s;
}

int Object::getX(){
    return x;
}

int Object::getY(){
    return y;
}

int Object::getWidth(){
    return w;
}

int Object::getHeight(){
    return h;
}

Sprite* Object::getSprite(){
    return sprite;
}

void Object::setX(int x){
    this->x = x;
}

void Object::setY(int y){
    this->y = y;
}

void Object::setWidth(int w){
    this->w = w;
}

void Object::setHeight(int h){
    this->h = h;
}

bool Object::canCollide(){
    return collider;
}

void Object::setCollider(bool col){
    collider = col;
}

bool Object::isColliding(Object *col){
   
    hit = 0x0; 

    /* --Hit Flags--
     *   0000 0000
     *   ???? LRTB 
     */
    if(col && this->collider && col->collider){

        int yIntersect;
        int xIntersect;

        // if col hits this on the left
        if(this->x <= col->x + col->w 
           && this->x > col->x){

            hit |= LEFT;
            xIntersect = (this->x - col->x + col->w) / (this->w + col->w);
        }
        // if col hits this on the right
        else if(this->x + this->w >= col->x
                && this->x <= col->x){

            hit |= RIGHT;
            xIntersect = (this->x + this->w - col->x) / (this->w + col->w);
        }

        if(hit){
            // if col hits this on the top
            if(this->y <= col->y + col->h
               && this->y >= col->y){

                hit |= TOP;
                yIntersect = (this->y - col->y + col->h) / (this->h + col->h);
            }
            // if col hits this on the bottom
            else if(this->y + this->h >= col->y
                    && this->y + this->h <= col->y + col->h){

                hit |= BOT;
                yIntersect = (this->y + this->h - col->y) / (this->h + col->h);
            }

            if(yIntersect < 0)
                yIntersect *= -1;
            if(xIntersect < 0) 
                xIntersect *= -1;

            yIntersect > xIntersect ? 
                hit &= 0x03 :
                hit &= 0x0C;

            this->col = col;
            return true;
        }
    }
    col = NULL; 
    hit = 0x0;
    return false;
}

void Object::handleCollision(){
   
    if(hit & LEFT){
        if(this->reactive)
            this->x += CORRECTION;
        
        if(col->reactive)
            col->x -= CORRECTION;
    }
    else if(hit & RIGHT){
        if(this->reactive)
            this->x -= CORRECTION;

        if(col->reactive)
            col->x += CORRECTION;
    }
    if(hit & TOP){
        if(this->reactive)
            this->y += CORRECTION;

        if(col->reactive)
            col->y -= CORRECTION;
    }
    else if(hit & BOT){
        if(this->reactive)
            this->y -= CORRECTION;

        if(col->reactive)
            col->y += CORRECTION;
    }
}

void Object::update(int dTime){
    x += velocityX * dTime;
    y += velocityY * dTime;
    sprite->update(dTime);
}
