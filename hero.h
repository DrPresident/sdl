#include <SDL/SDL.h>
#include "sprite.h"
#include "anim.h"

class Hero{
    public:
        Hero(const char* name = "name", const char* imgRes = "res/default.png", int x = 0, int y = 0);

        int loadSprite(const char* imgRes);

    private:
        Sprite sprite;
        Animation anims;
        const char* name;
        int x;
        int y;
        int numAnims;
};
