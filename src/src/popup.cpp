#include "popup.h"

Popup::Popup(Window *window) : GameObject(window){
	this->setSize(_window->getSizeX() / 4, (_window->getSizeY() / 8));
	this->setLocation(
		((_window->getSizeX() / 2) - this->getSizeX() / 2),
		((_window->getSizeY() / 2) - this->getSizeY() / 2)
	);
}

void Popup::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);
	_window->addText(x + 1, y + 1,_message);
}

void Popup::setMessage(string str){
	_message = str;
}

string Popup::getString(){
	return _window->getString(
		_posX + 1,
		_posY + 2
	);
}
