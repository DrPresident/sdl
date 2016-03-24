#include <SDL/SDL.h>
#include "object.h"

class Collider : Object{
    public:
        bool canCollide();
        void setCollider(bool col);
        bool isColliding(Collider*);
        void handleCollision();
        void update(int);

    private:
        bool reactive;
        int correction;
        char hit;
        enum{ LEFT = 0x08, RIGHT = 0x04, TOP = 0x02, BOT = 0x01 };
};
