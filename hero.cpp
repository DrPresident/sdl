#include "hero.h"

Hero::Hero(const char* name, const char* imgRes, int speed, int x, int y, int w, int h,
            int numAnims, int r, int c)
            : Visible(imgRes, x, y, w, h, numAnims, r, c, true, true){

    //TESTING
    sprite->addAnim(0, 3, 1000);
    //TESTING
    
    this->speed = speed;
    reactive = true;
    collider = true;

    this->name = name;
}

void Hero::update(int dTime){

    sprite->update(dTime);

    //DEBUGGING
    sprite->start();
    std::cout << "Hero::update" << std::endl;
    //DEBUGGING
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
