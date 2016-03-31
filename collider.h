#include <SDL/SDL.h>
#include "object.h"

class Collider : public Object{
    public:
        Collider(Object* par = this);
        bool canCollide();
        void setCollider(bool col);
        bool isColliding(Collider*);
        void update(int);

    private:
        void handleCollision();

        bool reactive;
        int correction;
        char hit;
        enum{ LEFT = 0x08, RIGHT = 0x04, TOP = 0x02, BOT = 0x01 };
        Object *par;
        Object *col;
};
