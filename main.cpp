#include <SDL/SDL.h>
#include "sprite.h"
#include "screen.h"
#include "hero.h"

int main(){

//    SDL_Surface *sprite = NULL;
//    SDL_Surface *screen = NULL;
//    SDL_Rect    rect;

    SDL_Init(SDL_INIT_EVERYTHING);

    Sprite guy("res/sprite.bmp");
    Screen screen(920, 1080);
/*
    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    sprite = SDL_LoadBMP("res/sprite.bmp");
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;
*/
    SDL_BlitSurface(guy.getSprite(), guy.getRect(), screen.getSurface(), NULL);

    SDL_Flip(screen.getSurface());

    SDL_Delay(2000);

    SDL_Quit();

    return 0;
}
