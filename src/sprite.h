#ifndef SPRITE
#define SPRITE

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>
#include <cassert>
#include "anim.h"

class Animation;

class Sprite{
    public:
        Sprite(const char* resource, int numAnims = 0, int r = 1, int c = 1);
        bool loadSprite(const char*);

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        
        void setX(int x);
        void setY(int y);
        void setWidth(int w);
        void setHeight(int h);
        
        virtual void update(int);
        
        SDL_Rect* getRect();
        SDL_Texture* getTexture();

        void play();
        void start();
        void stop();

        int getNumAnims();
        int addAnim(int startFrame, int frames, int msDelay);
        void setAnim(int);

    private:
        SDL_Texture* texture;
        std::vector<Animation> anims;

        int curAnim;
        int rows;
        int cols;
        int x;
        int y;
        int w;
        int h;

        friend class Animation;
};

#endif
