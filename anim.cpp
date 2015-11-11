#include "anim.h"

Animation::Animation(){

}

Animation::Animation(int rows, int cols){

}

int Animation::getFrames(){
   return totalRows * totalColumns;
}

int Animation::getColumns(){
    return totalColumns;
}

int Animation::getRows(){
    return totalRows;
}

SDL_Rect* Animation::getFrame(){
    
    SDL_Rect *rect = new SDL_Rect();

    rect->x = row * frameWidth;
    rect->y = col * frameHeight;
    rect->w = frameWidth;
    rect->h = frameHeight;

    return rect;
}
