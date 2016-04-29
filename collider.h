#ifndef COLLIDER_H
#define COLLIDER_H

#include <SDL/SDL.h>
#include "object.h"

#define CORRECTION 2

class Collider : public Object{
    public:
        Collider();
        Collider(Object* par);
        bool isColliding(Collider*);
        void update(int);

    protected:
        void handleCollision();

        bool reactive;
        bool collider;
        int correction;
        char hit;
        enum{ LEFT = 0x08, RIGHT = 0x04, TOP = 0x02, BOT = 0x01 };
        Object *par;
        Collider *col;
};

#endif
