#ifndef OBJECT
#define OBJECT

#include <cstddef>
#include <vector>

using namespace std;

class Object{
    public:
        Object();
        Object(int x, int y, int w, int h);
        Object(Object *parent);
        Object(Object *parent, int x, int y, int w, int h);

        bool attachTo(Object *par);
        bool attachChild(Object *child);

        int getX();
        int getY();
        int getWidth();
        int getHeight();

        void setX(int x);
        void setY(int y);
        void setWidth(int w);
        void setHeight(int h);
        
        void update(int);

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
