#include "popup.h"

Popup::Popup(Window *window) : GameObject(window){
	this->setSize(_window->getSizeX() / 4, (_window->getSizeY() / 8));
	this->setLocation(
		((_window->getSizeX() / 2) - this->getSizeX() / 2),
		((_window->getSizeY() / 2) - this->getSizeY() / 2)
	);
}

void Popup::draw(){
	this->drawBorder();
	_window->addText(
		((_window->getSizeX() / 2) - this->getSizeX() / 2) + 1,
		((_window->getSizeY() / 2) - this->getSizeY() / 2) + 1,
		_message);
}

void Popup::setMessage(const char *str){
	strcpy(_message, str);
}
