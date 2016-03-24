#ifndef CONTROLS
#define CONTROLS

#include <SDL2/SDL.h>
#include <map>
#include "anim.h"

template<typename T>
class Controls{
    public:
        Controls();
        Controls(T*);

        void checkInput(int);

        void bindQuit(void(*)());
        
        /* Sets up the key binding for a member function of T, 
         * it will overwrite a previous binding.
         */
        void bindControl(int, void (T::*)(int));

        /* Sets up the key binding for a single mouse key, 
         * keys set up this way take priority over the function
         * that controls all mouse key bindings.
         */
//        void bindControl(int, void (T::*)(int, int, int));

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
        std::map<int, void(*)(int)>     keyBindings;
        void (T::*mouseBinding)(int, int, int);
        std::map<int, void (T::*)(int, int,int)> separateMouseBindings;
        void (*quit)();
};

template <typename T>
Controls<T>::Controls(){
    
    character = NULL;
    mouseBinding = NULL;
    quit = NULL;
}

template <typename T>
Controls<T>::Controls(T* character){

    this->character = character;
}


template <typename T>
void Controls<T>::checkInput(int dTime){

    while(SDL_PollEvent(&event)){
         
        switch(event.type){
       
            case SDL_KEYDOWN:
                if(characterKeyBindings.find(event.key.keysym.sym) != characterKeyBindings.end())
                    (character->*(characterKeyBindings[event.key.keysym.sym]))(dTime);
                break;
        
            case SDL_KEYUP:

                break;
        
            case SDL_MOUSEBUTTONDOWN:
                
                // SINGLE MOUSE BUTTON FUNCTIONS
                if(separateMouseBindings.find(event.button.button) != separateMouseBindings.end())
                    (character->*(separateMouseBindings[event.button.button]))(event.button.button, event.button.x, event.button.y);

                // GENERAL MOUSE BUTTON FUNCTION
                else
                    (character->*(mouseBinding))(event.button.button, event.button.x, event.button.y);
                
                break;

            case SDL_MOUSEBUTTONUP:

                break;
        
            case SDL_QUIT:
                (*(quit))();
                break;      
        }
    }
}

template <typename T>
void Controls<T>::bindQuit(void (*q)()){
    quit = q;
}

template <typename T>
void Controls<T>::bindControl(int key, void (T::*func)(int)){
    
    characterKeyBindings.erase(key);
    keyBindings.erase(key);

    characterKeyBindings[key] = func;
}

/*
template <typename T>
void Controls<T>::bindControl(int key, void (T::*func)(int, int, int)){

    if(key < 3 && key > 0)
        separateMouseBindings[key] = func;
}
*/

template <typename T>
void Controls<T>::bindControl(void (T::*func)(int, int, int)){

    //separateMouseBindings.clear();
    mouseBinding = func;
}

template <typename T>
void Controls<T>::bindControl(int, void (*func)(int)){

    
}

#endif
