#include "SDL/SDL.h"
#include <vector>
#include <ctime>
#include "sprite.h"
#include "screen.h"
//#include "hero.h"
#include "instance.h"
#include "controls.h"

#define RUNTIME 10000

using namespace std;

const int FPS = 60;

int main(){

    int  startTime,
         curTime,
         dTime;

    SDL_Init(SDL_INIT_EVERYTHING);

//    Hero *hero     = new Hero("guy", "res/sprite.bmp", 10, 100, 100, 32, 32, 4, 4, 3);
//    Hero *testHero = new Hero("test", "res/sprite.bmp", 10, 90, 90, 32, 32, 4, 4, 3);
//    Visible background("res/blank.bmp", 0, 0, -1, -1, 0, 1, 1, false, false);
//    Controls<Hero> *controller = new Controls<Hero>(hero);
    Instance game;

    Screen mainWindow(1080, 920);

//    mainWindow.add(background);
//    mainWindow.add(*testHero);
//    mainWindow.add(*hero);

    game.addScreen(mainWindow);
    
//    controller->bindControl(SDLK_DOWN, &Hero::moveDown);

    startTime = SDL_GetTicks();
    curTime = startTime;

    for(dTime = 0; (curTime - startTime) < RUNTIME; dTime = SDL_GetTicks() - curTime){

//        controller->checkInput(dTime);

        if(dTime >= 1000 / FPS){
            curTime += dTime;
            game.updateScreens(dTime);
        }
    }

    SDL_Quit();

    return 0;
}
