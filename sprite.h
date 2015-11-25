#ifndef SPRITE
#define SPRITE

#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <vector>
#include "object.h"
#include "anim.h"

class Sprite : public Object{
    public:
        Sprite(const char* resource, int numAnims = 1, int r = 1, int c = 1);
        bool loadSprite(const char*);

        void update(int);
        
        SDL_Rect* getRect(){ return anim->getFrame(); } 
        SDL_Surface* getSprite(){ return sprite; }

        int getNumAnims(){ return anims.size(); }
        int addAnim(int startFrame, int frames, msDelay);


    private:
        SDL_Surface* sprite;
        vector<Animation> anims;

        int curAnim;
        int rows;
        int cols;

        friend class Animation;

};

#endif
