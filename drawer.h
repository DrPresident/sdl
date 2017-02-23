#ifndef DRAWER_H
#define DRAWER_H

#include "screen.h"
#include "anim.h"
#include "Sprite.h"

class Drawer {
    public:
        Drawer(Screen *scr);
        draw(Sprite *s);
        draw(Anim *a);

    private: 
        Screen *screen;
};

#endif
