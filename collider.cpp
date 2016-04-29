#include "collider.h"

Collider::Collider(){
    parent = this;
    x = parent->getX();
    y = parent->getY();
    w = parent->getWidth();
    h = parent->getHeight();
    reactive = false;
    col = NULL;
}

Collider::Collider(Object *par){
    parent = par;
    x = parent->getX();
    y = parent->getY();
    w = parent->getWidth();
    h = parent->getHeight();
    reactive = false;
    col = NULL;
}

void Collider::update(int dTime){
    if(par){
        
    }else{

    }

    if(col)
        handleCollision();
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
        if(parent->getX() <= col->x + col->w 
           && parent->getX() > col->x){

            hit |= LEFT;
            xIntersect = (parent->getX() - col->x + col->w) / (parent->getWidth() + col->w);
        }
        // if col hits this on the right
        else if(parent->getX() + parent->getWidth() >= col->x
                && this->x <= col->x){

            hit |= RIGHT;
            xIntersect = (parent->getX() + parent->getWidth() - col->x) 
                / (parent->getWidth() + col->w);
        }

        if(hit){
            // if col hits this on the top
            if(parent->getY() <= col->y + col->h
               && parent->getY() >= col->y){

                hit |= TOP;
                yIntersect = (parent->getY() - col->y + col->h) / (parent->getHeight() + col->h);
            }
            // if col hits this on the bottom
            else if(parent->getY() + parent->getHeight() >= col->y
                    && parent->getY() + parent->getHeight() <= col->y + col->h){

                hit |= BOT;
                yIntersect = (parent->getY() + parent->getHeight() - col->y) 
                    / (parent->getHeight() + col->h);
            }

            if(yIntersect < 0)
                yIntersect *= -1;
            if(xIntersect < 0) 
                xIntersect *= -1;

            yIntersect > xIntersect ? 
                hit &= 0x03 :
                hit &= 0x0C;

            //par->col = col;
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
