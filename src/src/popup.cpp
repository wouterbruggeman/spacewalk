#include "popup.h"

Popup::Popup(Window *window) : GameObject(window){
	this->setSize(POPUP_SIZE_X, POPUP_SIZE_Y);
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

string Popup::getString(int x, int y, int n){
	return _window->getString(
		_posX + x,
		_posY + y,
		n
	);
}

bool Popup::getBool(){
	this->draw();

	string answer = this->getString(_message.size() + 2, 1, 1);
	if(answer == "y"){
		return true;
	}else if(answer == "n"){
		return false;
	}else{
		return this->getBool();
	}
}
