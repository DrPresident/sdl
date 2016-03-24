#include "clicker.h"

Clicker::Clicker(Collider *col){

}

void Clicker::onClick(){

}

bool Clicker::isIn(int mx, int my){
    if(mx >= x && mx <= x + w
      && my >= y && my <= y + h)
        return true;
    return false;
}
