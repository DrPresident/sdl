#include "anim.h"

Animation::Animation(){

    xOffSet = 0;
    yOffSet = 0;
    frameWidth = 32;
    frameHeight = 32;
    row = 0;
    col = 0;
    startFrame = 1;
    totalRows = 1;
    totalColumns = 1;
    
}

Animation::Animation(int w, int h, int rows, int cols){

}

int Animation::getNumFrames(){
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
