#ifndef CONTROLS
#define CONTROLS

#include <SDL/SDL.h>
#include <map>
#include "anim.h"
#include "controlIFC.h"

template<class T>
class Controls{
    public:
        Controls();
        Controls(T);

        void checkInput(int);
        
        /* Sets up the key binding for a member function of
         * a class the derives from ControlIFC, will overwrite
         * a previous binding.
         */
        void bindControl(int, void (T::*)(int));

        /* Sets up the key binding for a single mouse key, 
         * keys set up this way take priority over the function
         * that controls all mouse key bindings.
         */
        void bindControl(int, void (T::*)(int, int, int));

        /* Binds all mouse keys to one function, will clear previous
         * bindings to mouse keys, but any set up after will have
         * higher priority.
         */
        void bindControl(void (T::*)(int, int, int));

        /* Binds the given key to a non-member function
         */
        void bindControl(int, void (*)(int));

        enum{
            NONE,
            QUIT
        };

    private:
        T* character;
        SDL_Event event;

        std::map<int, void (T::*)(int)> characterKeyBindings;
        std::map<int, void(*)(int)> keyBindings;
        void (ControlIFC::*mouseBinding)(int, int, int);
        std::map<int, void (T::*)(int, int,int)> spearateMouseBindings;

};

template <class T>
Controls::Controls(){
    
    character = NULL;
}

template <class T>
Controls::Controls(T* character){

    this->character = character;
}

template <class T>
void Controls::checkInput(int dTime){

    while(SDL_PollEvent(&event)){
         
        switch(event.type){
        
            case SDL_KEYDOWN:
                
                // CUSTOM BINDINGS
                if(customKeyBindings.find(event.key.keysym.sym) != customKeyBindings.end())
                    character->*(customKeyBindings[event.key.keysym.sym])();

                // DEFAULT BINDINGS
                else{

                    switch(defaultBindings[event.key.keysym.sym]){
                        case "MoveRight":
                            character->moveRight(dTime);
                            break;
                        case "MoveLeft":
                            character->moveLeft(dTime); 
                            break;
                        case "MoveUp":
                            character->moveUp(dTime);
                            break;
                        case "MoveDown":
                            character->moveDown(dTime);
                            break;
                        case "Jump":
                            character->jump(dTime);
                            break;
                        case "Attack":
                            character->attack(dTime);
                            break;
                        case "Shoot":
                            character->shoot(dTime);
                            break;
                    }
                }

                break;
        
            case SDL_KEYUP:

                break;
        
            case SDL_MOUSEBUTTONDOWN:
                
                // SINGLE MOUSE BUTTON FUNCTIONS
                if(customMouseBinding.find(event.button) != customMouseBinding.end())
                    character->*(customMouseBindings[event.button])(event.x, event.y);

                // GENERAL MOUSE BUTTON FUNCTION
                else
                    character->*(mouseBinding)(event.button, event.x, event.y);
                
                break;

            case SDL_MOUSEBUTTONUP:

                break;
        
            case SDL_QUIT:

                break;      
        }
    }
}

void Controls::bindControl(int key, void (T::*func)(int)){
    
    defaultBindings.erase(key);
    customMouseBindings.erase(key);

    customKeyBindings[key] = func;
}

void Controls::bindControl(int key, void (T::*func)(int, int, int)){

    if(key < 3 && key > 0)
        customMouseBindings[key] = func;
}

void Controls::bindControl(void (T::*func)(int, int, int)){

    customMouseBindings.clear();
    mouseBinding = func;
}

void Controls::bindControl(int, void(*func)(int)){

    
}

#endif
