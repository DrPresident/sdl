#include "controls.h"

Controls::Controls(){
    
    character = NULL;
}

Controls::Controls(ControlIFC* character){

    this->character = character;
}

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

void Controls::bindControl(int key, const char* binding){

    customKeyBindings.erase(key);
    customMouseBindings.erase(key);

    defaultBindings[key] = binding;
}

void Controls::bindControl(int key, void (ControlIFC::*func)(int)){
    
    defaultBindings.erase(key);
    customMouseBindings.erase(key);

    customKeyBindings[key] = func;
}

void Controls::bindControl(int key, void (ControlIFC::*func)(int, int, int)){

    if(key < 3 && key > 0)
        customMouseBindings[key] = func;
}

void Controls::bindControl(void (ControlIFC::*func)(int, int, int)){

    customMouseBindings.clear();
    mouseBinding = func;
}

