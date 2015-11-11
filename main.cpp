#include <SDL/SDL.h>

int main(){

    SDL_Surface *sprite = NULL;
    SDL_Surface *screen = NULL;
    SDL_Rect    rect;

    SDL_Init(SDL_INIT_EVERYTHING);

    screen = SDL_SetVideoMode(640, 480, 32, SDL_SWSURFACE);
    sprite = SDL_LoadBMP("res/sprite.bmp");
    rect.x = 0;
    rect.y = 0;
    rect.w = 32;
    rect.h = 32;

    SDL_BlitSurface(sprite, &rect, screen, NULL);

    SDL_Flip(screen);

    SDL_Delay(2000);

    SDL_Quit();

    return 0;
}
