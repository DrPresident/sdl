#ifndef VISIBLE
#define VISIBLE

#include "object.h"
#include "sprite.h"

class Visible : public Object{
    public:
        Visible(const char* imgRes = "res/default.bmp", 
                    int x = 0, int y = 0, int w = -1, int h = -1, 
                    int numAnims = 0, int r = 1, int c = 1, 
                    bool collider = true, bool reactive = false)
                : Object(x, y, 0, 0, collider, reactive){

            this->sprite = new Sprite(imgRes,numAnims, r, c);
            assert(this->sprite);

            
            if(this->w < 0)
                this->w = this->sprite->getSurface()->w;
            else
                this->w = w;

            if(this->h < 0)
                this->h = this->sprite->getSurface()->h;
            else
                this->h = h;
        }

        virtual void update(int dTime){ sprite->update(dTime); }
};

#endif
