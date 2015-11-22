#ifndef ANIM
#define ANIM

#include <SDL/SDL.h>

class Animation{
    public:

        Animation();
        Animation(SDL_Surface *sprite, int w, int h, int startFrame, int frames, 
                  int msDelay, int xOffset = 0, int yOffset = 0);

        void play(int loop = 1);
        void start();
        void stop();
        void update(int);

        SDL_Rect* getFrame();
        void jumpToFrame(int);

        int getNumFrames();
        void setNumFrames(int);

        void changeFrame(int);
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
        SDL_Surface* sprite;
};

#endif