#ifndef OBJECT
#define OBJECT

class Object{
    public:
        int getX(){ return x; }
        int getY(){ return y; }
        int getWidth(){ return w; }
        int getHeight(){ return h; }
        
        void moveX(int xDiff){ x += xDiff; }
        void moveY(int yDiff){ y += yDiff; }
        
        void setX(int x){ this->x = x; }
        void setY(int y){ this->y = y; }
        void setWidth(int w){ this->w = w; }
        void setHeight(int h){ this->y = y; }

    protected:
        int x;
        int y;
        int w;
        int h;
};

#endif
