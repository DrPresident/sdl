#ifndef CAMERA
#define CAMERA

#include <SDL2/SDL.h>

class Camera{
    public:
        Camera();
        
        void Zoom(int);
        
        void toWorldSpaceX(int x);
        void toWorldSpaceY(int y);

        void setMousePanning(bool pan);
        bool hasMousePanning();

        SDL_Rect* getRect();

    private:
        void updateRect();
        
        bool mousePanning;
        int panEdgeBuf;
        SDL_Rect *rect;

        int x;
        int y;
        int w;
        int h;
};

#endif
