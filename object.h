#ifndef OBJECT
#define OBJECT

#include "sprite.h"
#include <cstddef>

using namespace std;

class Object{
    public:
        Object();
        Object(int x, int y, int w, int h);

        int getX();
        int getY();
        int getWidth();
        int getHeight();
        Sprite* getSprite();

        void setX(int x);
        void setY(int y);
        void setWidth(int w);
        void setHeight(int h);
        
        bool canCollide();
        void setCollider(bool col);
        bool isColliding(Object*);
        void handleCollision();
        virtual void update();

        virtual void update(int);

    protected:
        int x;
        int y;
        int w;
        int h;
        int velocityX;
        int velocityY;
        int speed;
        int numAnims;

        Sprite *sprite;
        Object *col;

        bool collider;
        bool reactive;
        int correction;
        char hit;
        enum{ LEFT = 0x08, RIGHT = 0x04, TOP = 0x02, BOT = 0x01 };
};

#endif
