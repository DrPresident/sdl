#ifndef CONTROLS
#define CONTROLS

#include <SDL/SDL.h>
#include <map>
#include "anim.h"
#include "controlIFC.h"

class Controls{
    public:
        Controls();
        Controls(ControlIFC*);

        void checkInput(int);
        
        /* Sets up the binding for one of the default functions
         * for the ControlIFC, will overwrite a previous binding
         * for the same key.
         */
        void bindControl(int, const char*);
        
        /* Sets up the key binding for a member function of
         * a class the derives from ControlIFC, will overwrite
         * a previous binding.
         */
        void bindControl(int, void (ControlIFC::*)(int));

        /* Sets up the key binding for a single mouse key, 
         * keys set up this way take priority over the function
         * that controls all mouse key bindings.
         */
        void bindControl(int, void (ControlIFC::*)(int, int, int));

        /* Binds all mouse keys to one function, will clear previous
         * bindings to mouse keys, but any set up after will have
         * higher priority.
         */
        void bindControl(void (ControlIFC::*)(int, int, int));

        enum{
            NONE,
            QUIT
        };

    private:
        ControlIFC* character;
        SDL_Event event;

        std::map<int, const char*> defaultBindings;
        std::map<int, void (ControlIFC::*)(int)> customKeyBindings;
        void (ControlIFC::*mouseBinding)(int, int, int);
        std::map<int, void (ControlIFC::*)(int, int,int)> customMouseBindings;

};

#endif
