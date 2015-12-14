#ifndef CONTROL_IFC
#define CONTROL_IFC

class ControlIFC {
    public:
        virtual void moveLeft(int dTime) = 0;
        virtual void moveRight(int dTime) = 0;
        virtual void moveUp(int dTime) = 0;
        virtual void moveDown(int dTime) = 0;
        virtual void jump(int dTime) = 0;
        virtual void attack(int dTime) = 0;
        virtual void shoot(int dTime) = 0;
        virtual void onClick(int button, int x, int y) = 0;
};

#endif
