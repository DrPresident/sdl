#ifndef CAMERA
#define CAMERA

#include <SDL/SDL.h>
#include "object.h"

class Camera : public Object{
    public:
        Camera();
        
        void Zoom(int);
        
        void toWorldSpaceX(int x);
        void toWorldSpaceY(int y);

        SDL_Rect* getRect();

    private:
        void updateRect();

        SDL_Rect *rect;
};

#endif
