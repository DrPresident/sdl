#include "screen.h"

using namespace std;

Screen::Screen(int w, int h, int fps){
    
    screen = SDL_CreateWindow("WINDOW",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0);
    this->fps = fps;
    render = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
    
}

void Screen::update(int dTime){
   
    SDL_Rect position;

    //check Collisions
    for(int x = 0; x < colliders.size() - 1; x++)
        for(int y = x + 1; y < colliders.size(); y++){
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

        SDL_RenderCopy(render, drawn[i]->get(), drawn[i]->getRect(), screen, &position);
    }
    
//    SDL_Flip(screen);
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

void Screen::setFPS(int fps){
    this->fps = fps;
}

SDL_Renderer* Screen::getRenderer(){
    return render;
}

SDL_Window* Screen::getScreen(){
    return screen;
}
