#include "anim.h"

Animation::Animation(){

    xOffset = 0;
    yOffset = 0;
    frameWidth = 32;
    frameHeight = 32;
    numFrames = 1;
    startFrame = 1;
    timer = 0;
    
}

Animation::Animation(SDL_Surface *sprite, int startFrame, int frames, 
                     int msDelay){

    this->sprite = sprite;
    
    frameWidth = (sprite->w - xOffset) / sprite->cols;
    frameHeight = (sprite->h - yOffset) / sprite->rows;
    
    startFrame = start;
    numFrames = frames;
    delay = msDelay;
    
    this->xOffset = 0;
    this->yOffset = 0;

    curFrame = startFrame;
    timer = 0;
    loops = 0;
    playing = false;
    stopping = false; 
}

void Animation::play(int loop){
    loops = loop;
    playing = true;
}

void Animation::start(){
    
    stopping = false;
    playing = true;
    loops = -1;
}

void Animation::stop(){
    if(playing)
        stopping = true;
    else
        stopping = false;
}

void Animation::update(int dTime){
    if(playing){

        timer += dTime;
        
        // advance to next frame if past delay
        if(timer >= delay){
            curFrame = ((curFrame + 1) % (numFrames + startFrame)) + startFrame;

            // check for beginning of animation
            if(curFrame == startFrame){
                // check for continuous animation
                if(loops >= 0){
                    if(loops > 0){
                        loops--;
                    }
                    else{
                        playing = false;
                    }
                }
                // stopping
                if(stopping){

                    stopping = false;
                    playing = false;
                    loops = 0;
                }
            }
        }
    }
}

int Animation::getNumFrames(){
   return numFrames;
}

SDL_Rect* Animation::getFrame(){
    
    SDL_Rect *rect = new SDL_Rect();

    rect->x = xOffset + (frameWidth * curFrame);
    rect->y = yOffset + (frameHeight * curFrame);
    rect->w = frameWidth;
    rect->h = frameHeight;

    return rect;
}
