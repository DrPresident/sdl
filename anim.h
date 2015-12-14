#ifndef ANIM
#define ANIM

#include <SDL/SDL.h>
#include <cassert>
#include "sprite.h"

class Sprite;

class Animation{
    public:

        Animation();
        Animation(Sprite *sprite, int startFrame, int frames, 
                  int msDelay);

        void play(int loop = 1);
        void start();
        void stop();
        void update(int);

        SDL_Rect* getFrame();

        int getNumFrames();
        void setNumFrames(int);

        void setFrame(int);

    private:

        int totalRows,
            totalColumns,
            row,
            col,
            frameHeight,
            frameWidth,
            numFrames,
            xOffset,
            yOffset,
            startFrame,
            curFrame,
            delay,
            timer,
            loops;

        bool playing;
        bool stopping;
        Sprite* sprite;
        SDL_Rect *rect;
        
};

#endif
