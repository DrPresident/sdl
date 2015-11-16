#ifndef SCREEN
#define SCREEN

#include <vector>
#include <algorithm>
#include "object.h"
#include "visible.h"

class Screen{
    public:
        Screen();

        void update();
        void add(Visible&);
        void remove(Object&);

    private:
        std::vector<Object*> drawn;
        //std::vector<Collider*> colliders;
};

#endif
