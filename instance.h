#ifndef INSTANCE
#define INSTANCE

#include <algorithm>
#include "screen.h"
#include "controls.h"
#include "clicker.h"
#include "collider.h"
#include "sprite.h"

class Instance{
    public:
        void run();
        void updateScreens(int);

        void addScreen(Screen*);
        void addCollider(Collider*);
        void addSprite(Sprite*);
        void removeScreen(Screen*);

    private:
        std::vector<Screen*> screens;
        std::vector<Collider*> cols;
        std::vector<Sprite*> drawn;
        std::vector<Clicker*> clickers;
};

#endif
