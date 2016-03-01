#include "screen.h"

#include <iostream>

using namespace std;

Screen::Screen(int w, int h, int fps){
    
    screen = SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE);
    this->fps = fps;
}

void Screen::update(int dTime){
   
    SDL_Rect position;

    //check Collisions
    for(int x = 0; x < colliders.size() - 1; x++)
        for(int y = x + 1; y < colliders.size(); y++){
            cout << "checking " << x << ',' << y << endl;
            if(colliders[x]->isColliding(colliders[y]))
                colliders[x]->handleCollision();
        }

    //drawing
    for(int i = 0; i < drawn.size(); i++){

        drawn[i]->update(dTime);

        position.x = drawn[i]->getX();
        position.y = drawn[i]->getY();
        position.h = drawn[i]->getHeight();
        position.w = drawn[i]->getWidth();

        SDL_BlitSurface(drawn[i]->getSurface(), drawn[i]->getRect(), screen, &position);
    }
    
    SDL_Flip(screen);
}

void Screen::add(Visible &vis){

    drawn.push_back(&vis);

    if(vis.canCollide())
        colliders.push_back(&vis);
}

void Screen::add(Object &obj){
    
    if(obj.canCollide())
        colliders.push_back(&obj);
}

void Screen::remove(Object &obj){

    drawn.erase(find(drawn.begin(), drawn.end(), &obj));
}

void Screen::clear(){
    
    drawn.clear();
    colliders.clear();
    cameras.clear();
}


