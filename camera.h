#ifndef CAMERA
#define CAMERA

#include <SDL/SDL.h>

class Camera{
    public:
        Camera();
        
        int     X();
        void    X(int);
        int     Y();
        void    Y(int);
        void    Zoom(int);

        SDL_Rect* getRect();

    private:
        int x,
            y,
            w,
            h;

        void updateRect();

        SDL_Rect *rect;
};

#endif
