#include "collider.h"

Collider::Collider(Object *par){
    parent = par;
    x = par->x;
    y = par->y;
    w = par->w;
    h = par->h;
}

void Collider::update(int dTime){
    if(par){
        
    }else{

    }
}

bool Collider::canCollide(){
    return collider;
}

void Collider::setCollider(bool col){
    collider = col;
}

bool Collider::isColliding(Collider *col){
   
    hit = 0x0; 

    /* --Hit Flags--
     *   0000 0000
     *   ???? LRTB 
     */
    if(col && this->collider && col->collider){

        int yIntersect;
        int xIntersect;

        // if col hits this on the left
        if(par->x <= col->x + col->w 
           && par->x > col->x){

            hit |= LEFT;
            xIntersect = (par->x - col->x + col->w) / (par->w + col->w);
        }
        // if col hits this on the right
        else if(par->x + par->w >= col->x
                && this->x <= col->x){

            hit |= RIGHT;
            xIntersect = (par->x + par->w - col->x) / (par->w + col->w);
        }

        if(hit){
            // if col hits this on the top
            if(par->y <= col->y + col->h
               && par->y >= col->y){

                hit |= TOP;
                yIntersect = (par->y - col->y + col->h) / (par->h + col->h);
            }
            // if col hits this on the bottom
            else if(par->y + par->h >= col->y
                    && par->y + par->h <= col->y + col->h){

                hit |= BOT;
                yIntersect = (par->y + par->h - col->y) / (par->h + col->h);
            }

            if(yIntersect < 0)
                yIntersect *= -1;
            if(xIntersect < 0) 
                xIntersect *= -1;

            yIntersect > xIntersect ? 
                hit &= 0x03 :
                hit &= 0x0C;

            par->col = col;
            return true;
        }
    }
    col = NULL; 
    hit = 0x0;
    return false;
}

void Collider::handleCollision(){
   
    if(hit & LEFT){
        if(this->reactive)
            this->x += CORRECTION;
        
        if(col->reactive)
            col->x -= CORRECTION;
    }
    else if(hit & RIGHT){
        if(this->reactive)
            this->x -= CORRECTION;

        if(col->reactive)
            col->x += CORRECTION;
    }
    if(hit & TOP){
        if(this->reactive)
            this->y += CORRECTION;

        if(col->reactive)
            col->y -= CORRECTION;
    }
    else if(hit & BOT){
        if(this->reactive)
            this->y -= CORRECTION;

        if(col->reactive)
            col->y += CORRECTION;
    }
}
