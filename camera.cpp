#include "camera.h"

Camera::Camera(){
    x = 0;
    y = 0;
    w = 100;
    h = 100;

    rect = new SDL_Rect();
}

void Camera::Zoom(int z){
    x += z;
    y += z;
    h -= -z;
    w -= -z;
    updateRect();
}

void Camera::setMousePanning(bool pan){
    mousePanning = pan;
}

bool Camera::hasMousePanning(){
    return mousePanning;
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
