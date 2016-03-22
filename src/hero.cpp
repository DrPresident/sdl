#include "hero.h"
#include <cmath>

Hero::Hero(int x, int y, int w, int h,
            int numAnims, int r, int c, 
            const char* imgRes, int speed){

    this->sprite = new Sprite(imgRes,numAnims, r, c);

    
    if(this->w < 0)
        this->w = this->sprite->getWidth();
    else
        this->w = w;

    if(this->h < 0)
        this->h = this->sprite->getHeight();
    else
        this->h = h;
    sprite->addAnim(0, 3, 1000);
    
    this->speed = speed;
    velocityX = 0;
    velocityY = 0;

    reactive = true;
    collider = true;

    this->name = name;
}

void Hero::update(int dTime){
    
    x += velocityX * dTime;
    y += velocityY * dTime;

    if(velocityX || velocityY){
        if(abs(velocityX) > abs(velocityY)){
            if(velocityX > 0)
                getSprite()->setAnim(2);
            else
                getSprite()->setAnim(1);
        }
        else{
            if(velocityY > 0)
                getSprite()->setAnim(3);
            else
                getSprite()->setAnim(0);
        }
        sprite->start();
    }
    sprite->update(dTime);

}

void Hero::moveLeft(){
    velocityX = -speed;
}

void Hero::moveRight(){
    velocityX = speed;
}

void Hero::moveUp(){
    velocityY = -speed;
}

void Hero::moveDown(){
    velocityY = speed;
}
