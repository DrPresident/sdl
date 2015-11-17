#ifndef SCREEN
#define SCREEN

#include <vector>
#include <algorithm>
#include "object.h"
#include "visible.h"
#include "camera.h"

class Screen{
    public:
        Screen(int w = 640, int h = 480);

        void update();
        void add(Visible&);
        void remove(Object&);
        void clear();

        SDL_Surface* getSurface(){ return screen; }

    private:
        std::vector<Visible*> drawn;
        //std::vector<Collider*> colliders;
        std::vector<Camera*> cameras;

        SDL_Surface *screen;
};

#endif
