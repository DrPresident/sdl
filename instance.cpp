#include "instance.h"

void Instance::run(){

}

void Instance::updateScreens(int dTime){
    
    for(int i = 0; i < screens.size(); i++)
        screens[i]->update(dTime);
}

void Instance::removeScreen(Screen& scr){ 
    screens.erase(std::find(screens.begin(), screens.end(), &scr)); 
}


