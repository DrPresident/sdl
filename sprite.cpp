#include "sprite.h"

Sprite::Sprite(SDL_Renderer *render, const char* resource, int numAnims, int r, int c){
    
    texture = NULL;
    renderer = render;
    loadSprite(resource);
    
    curAnim = 0;
    rows = r;
    cols = c;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
}

bool Sprite::loadSprite(const char* resource){

    if(texture)
        SDL_DestroyTexture(texture);

    SDL_Surface *s = IMG_Load(resource);
    texture = SDL_CreateTextureFromSurface(renderer, s);
    SDL_FreeSurface(s);
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);

    return true;
}
/*
int Sprite::getX(){
    return x;
}

int Sprite::getY(){
    return y;
}

int Sprite::getWidth(){
    return w;
}

int Sprite::getHeight(){
    return h;
}

void Sprite::setX(int x){
    this->x = x;
}

void Sprite::setY(int y){
    this->y = y;
}

void Sprite::setWidth(int w){
    this->w = w;
}

void Sprite::setHeight(int h){
    this->h = h;
}
*/
void Sprite::update(int dTime){

    if(curAnim < anims.size())
        anims[curAnim].update(dTime);
}

SDL_Rect* Sprite::getRect(){
     
    if(anims.size() > 0){
        assert(anims[curAnim].getFrame());
        return anims[curAnim].getFrame();
    }
    
    return NULL; 
    
}

SDL_Texture* Sprite::getTexture(){
    return texture;
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

void Sprite::setAnim(int a){
    curAnim = a % anims.size();
}

