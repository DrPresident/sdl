#include "screen.h"

#include <iostream>

using namespace std;

Screen::Screen(int w, int h, int fps){
    
    screen = SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE);
    this->fps = fps;
}

void Screen::update(int dTime){
   
    SDL_Rect position;
    SDL_Delay(1 / fps);

    for(int i = 0; i < drawn.size(); i++){

        drawn[i]->update(dTime);

        position.x = drawn[i]->getX();
        position.y = drawn[i]->getY();
        position.h = drawn[i]->getHeight();
        position.w = drawn[i]->getWidth();

        SDL_BlitSurface(drawn[i]->getSprite(), drawn[i]->getRect(), screen, &position);
    }
    SDL_Flip(screen);
}

void Screen::add(Visible &vis){

    drawn.push_back(&vis);
}

void Screen::remove(Object &obj){

    drawn.erase(find(drawn.begin(), drawn.end(), &obj));
}

void Screen::clear(){
    
    drawn.clear();
//    colliders.clear();
    cameras.clear();
}
