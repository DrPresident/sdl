#include <SDL/SDL.h>
#include <vector>
#include <ctime>
#include "sprite.h"
#include "screen.h"
#include "hero.h"
#include "instance.h"

using namespace std;

const time_t fps = 60;

int main(){

    bool quit = false;
    time_t startTime;
    time_t curTime;
    time_t endTime;
    time_t dTime;

    SDL_Init(SDL_INIT_EVERYTHING);

    Hero guy("guy", "res/sprite.bmp", 100, 100);

    Instance game;

    Screen mainWindow(1080, 920);
    mainWindow.add(guy);

    game.addScreen(mainWindow);
    
    startTime = time(NULL);
    curTime = startTime;
    dTime = startTime;
    
    for(;(curTime - startTime) < 4000; dTime = time(NULL) - curTime){

        if(dTime >= 1 / fps){
            curTime += dTime;
        
            game.updateScreens(dTime);
        }
    }

    SDL_Delay(4000);

    SDL_Quit();

    return 0;
}
