#ifndef SCREEN
#define SCREEN

#include <vector>
#include <algorithm>
#include "object.h"
#include "visible.h"
#include "camera.h"
#include "collider.h"

class Screen{
    public:
        Screen(int w = 640, int h = 480, int fps = 60);

        void update(int);
        void add(Visible&);
        void add(Object&);
        void remove(Object&);
        void clear();
        void setFPS(int fps){ this->fps = fps; }

        SDL_Surface* getSurface(){ return screen; }

    private:
        std::vector<Visible*> drawn;
        std::vector<Object*> colliders;
        std::vector<Camera*> cameras;

        SDL_Surface *screen;

        int fps;
};

#endif
