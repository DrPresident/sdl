#include "screen.h"

using namespace std;

Screen::Screen(int w, int h){
    screen = SDL_SetVideoMode(w, h, 32, SDL_SWSURFACE);
}

void Screen::update(){
    
    for(int i = 0; i < drawn.size(); i++){
        SDL_BlitSurface(drawn[i]->getSprite(), drawn[i]->getRect(), screen, NULL); 
    }
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
