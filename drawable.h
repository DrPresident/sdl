#include "sprite.h"
#include "object.h"

class Drawable : public Object{
    public:
        Sprite getSprite();

        virtual void update(int dTime);
    protected:
        Sprite sprite;
};
