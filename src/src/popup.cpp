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
	for(int i = 0; i < MESSAGE_SIZE_Y; i++){
		_window->addText(x + 1, y + 1 + i, _message[i]);
	}
}

void Popup::setMessage(string str, int index){
	_message[index] = str;
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
	_window->addText(_posX + 1, _posY + (POPUP_SIZE_Y - 2), POPUP_BOOL_ANSWERS);

	char answer = getch();

	if(answer == 'y' || answer == 'Y'){
		return true;
	}else if(answer == 'n' || answer == 'N'){
		return false;
	}else{
		return this->getBool();
	}
}
