#include "spaceship.h"

SpaceShip::SpaceShip(unsigned char size, Player *owner, Window *window) : GameObject(window){
	_size = size;
	_owner = owner;
	_destroyed = false;
}

void SpaceShip::draw(bool selected){
	this->draw(_posX, _posY, selected);
}

void SpaceShip::draw(int x, int y, bool selected){
	//size determines the amount of '='

	int color = COLOR_GREEN_BLACK;
	if(selected){
		color = COLOR_BLACK_GREEN;
	}

	int i = 0;
	for(; i < _size; i++){
		_window->addText(x + i, y, SPACESHIP_OTHER_CHAR, color);
	}
	_window->addText(x + i, y, SPACESHIP_TOP_CHAR, color);
}

void SpaceShip::destroy(){
	_destroyed = true;
}

bool SpaceShip::isDestroyed(){
	return _destroyed;
}
