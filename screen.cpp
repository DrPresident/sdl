#include "screen.h"

using namespace std;

Screen::Screen(){

}

void Screen::update(){

}

void Screen::add(Visible &vis){

    drawn.push_back(&vis);
}

void Screen::remove(Object &obj){

    drawn.erase(find(drawn.begin(), drawn.end(), &obj));
}
