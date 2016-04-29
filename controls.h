#ifndef CONTROLS
#define CONTROLS

#include <SDL2/SDL.h>
#include <vector>
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

        std::vector<void (T::*)(int)>   objectBindings;
        std::vector<void (*)(int)>      globalBindings;
        
        void (T::*objectMouseBinding)(int, int, int);
        void (*globalMouseBinding)(int, int, int);
        void (*quit)();
};

template <typename T>
Controls<T>::Controls(){
    
    character = NULL;
    objectMouseBinding = NULL;
    globalMouseBinding = NULL;
    quit = NULL;
    for(int i = 0; i < 100; i++){
        objectBindings[i] = NULL;
        globalBindings[i] = NULL;
    }
}

template <typename T>
Controls<T>::Controls(T* character){
    this->character = character;
    objectMouseBinding = NULL;
    globalMouseBinding = NULL;
    quit = NULL;
    for(int i = 0; i < 100; i++){
        objectBindings[i] = NULL;
        globalBindings[i] = NULL;
    }
}


template <typename T>
void Controls<T>::checkInput(int dTime){

    while(SDL_PollEvent(&event)){
         
        switch(event.type){
       
            case SDL_KEYDOWN:
                if(objectBindings[event.key.keysym.sym])
                    (character->*(objectBindings[event.key.keysym.sym]))(dTime);
                if(globalBindings[event.key.keysym.sym])
                    (globalBindings[event.key.keysym.sym])(dTime);
                break;
        
            case SDL_KEYUP:

                break;
        
            case SDL_MOUSEBUTTONDOWN:
                if(objectMouseBinding)
                    (character->*(objectMouseBinding))(event.button.button, 
                            event.button.x, event.button.y);
                if(globalMouseBinding)
                    *(globalBindings)(event.button.button, 
                            event.button.x, event.button.y);
                
                break;

            case SDL_MOUSEBUTTONUP:

                break;
        
            case SDL_QUIT:
                if(quit)
                    *(quit)();
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
 
    globalBindings[key] = NULL;   
    objectBindings[key] = func;
}

template <typename T>
void Controls<T>::bindControl(void (T::*func)(int, int, int)){

    objectMouseBinding = func;
}

template <typename T>
void Controls<T>::bindControl(int key, void (*func)(int)){

    globalBindings[key] = func;
}

#endif
