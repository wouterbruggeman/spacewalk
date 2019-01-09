#include "popup.h"

Popup::Popup(Window *window) : GameObject(window){
	this->setSize(_window->getSizeX() / 2, (_window->getSizeY() / 4));
	this->setLocation(
		((_window->getSizeX() / 2) - this->getSizeX() / 2),
		((_window->getSizeY() / 4) - this->getSizeY() / 4)
	);
}

void Popup::draw(){
	this->drawBorder();
}
