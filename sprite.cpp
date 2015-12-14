#include "sprite.h"

Sprite::Sprite(const char* resource, int numAnims, int r, int c){
    
    surface = IMG_Load(resource);
    
    curAnim = 0;
    rows = r;
    cols = c;

}

bool Sprite::loadSprite(const char* resource){

    SDL_FreeSurface(surface);
    surface = IMG_Load(resource);

    return true;
}

void Sprite::update(int dTime){

    if(curAnim < anims.size())
        anims[curAnim].update(dTime);
}

SDL_Rect* Sprite::getRect(){
    
    //DEBUGGING
    std::cout << "curAnim -    " << curAnim << std::endl
              << "anims.size - " << anims.size() << std::endl;
    //DEBUGGING
    
    if(anims.size() > 0){
        assert(anims[curAnim].getFrame());
        std::cout << "frame w - " << anims[curAnim].getFrame()->w << std::endl
                  << "frame h - " << anims[curAnim].getFrame()->h << std::endl;
        return anims[curAnim].getFrame();
    }
    
    return NULL; 
    
}

SDL_Surface* Sprite::getSurface(){
    return surface;
}

void Sprite::play(){
    anims[curAnim].play();
}

void Sprite::start(){
    anims[curAnim].start();
}

void Sprite::stop(){
    anims[curAnim].stop();
}

int Sprite::getNumAnims(){
    return anims.size();
}

int Sprite::addAnim(int startFrame, int frames, int msDelay){

    anims.push_back(Animation(this, startFrame, frames, msDelay)); 

    return anims.size() - 1;
}
