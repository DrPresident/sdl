#ifndef ANIM
#define ANIM

#include "SDL2/SDL.h"
#include <cassert>
#include "sprite.h"

class Sprite;

class Animation{
    public:

        Animation();
        Animation(Sprite *sprite, int rows, int cols, int msDelay, 
                  int startFrame = 0);

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
            rows,
            col,
            cols,
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
