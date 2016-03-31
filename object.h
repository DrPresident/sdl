#ifndef OBJECT
#define OBJECT

#include "sprite.h"
#include <cstddef>
#include <vector>

using namespace std;

class Object{
    public:
        Object();
        Object(int x, int y, int w, int h);

        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void setX(int x);
        void setY(int y);
        void setWidth(int w);
        void setHeight(int h);
        
        virtual void update(int);

    protected:
        int x;
        int y;
        int w;
        int h;

        Object *parent;
        vector<Object*> children;
//MOVE ELSEWHERE
        int velocityX;
        int velocityY;
        int speed;
};

#endif
