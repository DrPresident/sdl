#include "clicker.h"

Clicker::Clicker(){

}

bool Clicker::isIn(int mx, int my){
    if(mx >= x && mx <= x + w
      && my >= y && my <= y + h)
        return true;
    return false;
}
