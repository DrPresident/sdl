#ifndef SCREEN
#define SCREEN

#include <vector>
#include <algorithm>
#include <SDL2/SDL.h>
#include "object.h"
//#include "visible.h"
#include "camera.h"
#include "collider.h"
#include "drawable.h"

class Screen{
    public:
        Screen(int w = 640, int h = 480, int fps = 60);

        virtual void update(int);
        void draw();
        void add(Object&);
        void remove(Object&);
        void clear();
        void setFPS(int fps);
        SDL_Renderer *getRenderer();

        SDL_Window* getScreen();

    private:
        std::vector<Drawable*> drawn;
        std::vector<Collider*> colliders;
        std::vector<Camera*> cameras;

        SDL_Window *screen;
        SDL_Renderer *render;

        int fps;
};

#endif
