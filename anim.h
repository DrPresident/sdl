#ifndef ANIM
#define ANIM

#include <SDL/SDL.h>

class Animation{
    public:

        Animation();
        Animation(int w, int h, int rows, int cols);

        int getColumns();
        int getRows();

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
            xOffSet,
            yOffSet,
            startFrame,
            curFrame,
            delay;

        SDL_Surface* sprite;
};

#endif
