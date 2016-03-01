#include "anim.h"

Animation::Animation(){

    xOffset = 0;
    yOffset = 0;
    frameWidth = 32;
    frameHeight = 32;
    numFrames = 1;
    startFrame = 1;
    timer = 0;
    rect = new SDL_Rect();
    rect->w = frameWidth;
    rect->h = frameHeight;
}

Animation::Animation(Sprite *sprite, int startFrame, int frames, 
                     int msDelay){

    this->sprite = sprite;
 
    this->xOffset = 0;
    this->yOffset = 0;
   
    frameWidth = (sprite->surface->w - xOffset) / sprite->cols;
    frameHeight = (sprite->surface->h - yOffset) / sprite->rows;
    
    this->startFrame = startFrame;
    numFrames = frames;
    delay = msDelay;
    

    curFrame = startFrame;
    timer = 0;
    loops = 0;
    playing = false;
    stopping = false;

    rect = new SDL_Rect();
    rect->w = frameWidth;
    rect->h = frameHeight;
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
            timer = 0;
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
    rect->x = ((curFrame % sprite->cols) * frameWidth) + xOffset;
    rect->y = ((curFrame / sprite->cols) * frameHeight) + yOffset;
}

SDL_Rect* Animation::getFrame(){

    assert(rect);
    return rect;
}

int Animation::getNumFrames(){
    return numFrames;
}

void Animation::setNumFrames(int num){
    numFrames = num;
}

void Animation::setFrame(int frame){
    curFrame = frame % numFrames;
}
