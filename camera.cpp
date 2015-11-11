#include "camera.h"

Camera::Camera(){
    x = 0;
    y = 0;
    w = 100;
    h = 100;

    rect = new SDL_Rect();
}

int Camera::X(){
    return x;
}

void Camera::X(int x){
    this->x = x;
    updateRect();
}

int Camera::Y(){
    return y;
}

void Camera::Y(int y){
    this->y = y;
    updateRect();
}

void Camera::Zoom(int z){
    x += z;
    y += z;
    h -= -z;
    w -= -z;
    updateRect();
}

SDL_Rect* Camera::getRect(){
    return rect;
}

void Camera::updateRect(){
    rect->x = x;
    rect->y = y;
    rect->w = w;
    rect->h = h;
}
