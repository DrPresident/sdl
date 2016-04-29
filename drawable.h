#include "sprite.h"
#include "object.h"

class Drawable : public Object{
    public:
        Sprite getSprite();
        SDL_Rect* getRect();

        void update(int dTime);
    protected:
        Sprite sprite;
};
