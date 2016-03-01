#ifndef OBJECT
#define OBJECT

#include <cstddef>

#include <iostream>
using namespace std;

class Object{
    public:
        Object();
        Object(int x, int y, int w = 0, int h = 0, 
                bool collider = true, bool reactive = false);

        int getX(){ return this->x; }
        int getY(){ return this->y; }
        int getWidth(){ return this->w; }
        int getHeight(){ return this->h; }
        
        void moveX(int xDiff){ this->x += xDiff; }
        void moveY(int yDiff){ this->y += yDiff; }
        
        void setX(int x){ this->x = x; }
        void setY(int y){ this->y = y; }
        void setWidth(int w){ this->w = w; }
        void setHeight(int h){ this->y = y; }

        bool canCollide(){ return collider; }
        void setCollider(bool col){ collider = col; }

        bool isColliding(Object*);

        void handleCollision();

    protected:
        int x;
        int y;
        int w;
        int h;

        Object *col;
        bool collider;
        bool reactive;
        int correction;
        char hit;
        enum{ LEFT = 0x08, RIGHT = 0x04, TOP = 0x02, BOT = 0x01 };
};

#endif
