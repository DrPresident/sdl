#include "hero.h"
#include <cmath>

Hero::Hero(const char* name, const char* imgRes, int speed, int x, int y, int w, int h,
            int numAnims, int r, int c)
            : Visible(imgRes, x, y, w, h, numAnims, r, c, true, true){

    //TESTING
    sprite->addAnim(0, 3, 1000);
    //TESTING
    
    this->speed = speed;
    velocityX = 0;
    velocityY = 0;

    reactive = true;
    collider = true;

    this->name = name;
}

void Hero::update(int dTime){

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

void Hero::moveLeft(int dTime){
    x -= speed * dTime;
}

void Hero::moveRight(int dTime){
    x += speed * dTime;
}

void Hero::moveUp(int dTime){
    y -= speed * dTime;
}

void Hero::moveDown(int dTime){
    y += speed * dTime;
}

/*
void Hero::jump(int dTime){}

void Hero::attack(int dTime){
    
}

void Hero::shoot(int dTime){

}

void Hero::onClick(int button, int x, int y){

}
*/
