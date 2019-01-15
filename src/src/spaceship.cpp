#include "spaceship.h"

SpaceShip::SpaceShip(int size, Player *owner, Window *window) : GameObject(window){
	_size = size;
	_owner = owner;
}

void SpaceShip::draw(){

	//Size determines the amount of '='
	int i = 0;
	for(; i < _size; i++){
		_window->addText(_posX + i, _posY, SPACESHIP_OTHER_CHAR, COLOR_GREEN_BLACK);
	}
	_window->addText(_posX + i, _posY, SPACESHIP_TOP_CHAR, COLOR_GREEN_BLACK);
}
