#include "gameobject.h"

GameObject::GameObject(Window *window){
	_window = window;
	this->setLocation(0,0);
}

GameObject::~GameObject(){

}

void GameObject::setLocation(int x, int y){
	_posX = x;
	_posY = y;
}
