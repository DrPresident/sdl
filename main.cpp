#include "SDL2/SDL.h"
#include <vector>
#include <ctime>
#include "sprite.h"
#include "screen.h"
#include "tmp/hero.h"
#include "instance.h"
#include "controls.h"

#define RUNTIME 10000

using namespace std;

const int FPS = 60;

bool q = false;
void quit(){ 
    SDL_Quit();
    q = true; 
}

int main(){

    int  startTime,
         curTime,
         dTime;

    SDL_Init(SDL_INIT_EVERYTHING);
    
    Screen mainWindow(1080, 920);

    Hero *hero     = new Hero(&mainWindow, "res/sprite.bmp", 100, 100, 32, 32, 4, 4, 3, 10);
    Hero *testHero = new Hero(&mainWindow, "res/sprite.bmp", 90, 90, 32, 32, 4, 4, 3, 10);
//    Visible background("res/blank.bmp", 0, 0, -1, -1, 0, 1, 1, false, false);
    Controls<Hero> *controller = new Controls<Hero>(hero);
    Instance game;



 //   mainWindow.add(background);
    mainWindow.add(*testHero);
    mainWindow.add(*hero);

    game.addScreen(&mainWindow);
    
    controller->bindControl(SDLK_DOWN, &Hero::moveDown);
    controller->bindQuit(&quit);

    startTime = SDL_GetTicks();
    curTime = startTime;

    for(dTime = 0; (curTime - startTime) < RUNTIME; dTime = SDL_GetTicks() - curTime){

        controller->checkInput(dTime);
        if(q) break;

        if(dTime >= 1000 / FPS){
            curTime += dTime;
            game.updateScreens(dTime);
        }
    }

    return 0;
}
