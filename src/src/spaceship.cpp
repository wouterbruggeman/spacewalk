#include "spaceship.h"

SpaceShip::SpaceShip(unsigned char size, int color, int colorSelected,
	Player *owner, Window *window)
	: GameObject(window),
	SelectableObject(color, colorSelected)
{
	_size = size;
	_owner = owner;
	_state = SpaceShip::UNPLACED;
}

void SpaceShip::draw(){
	this->draw(_posX, _posY);
}

void SpaceShip::draw(int x, int y){
	//size determines the amount of '='

	int color = getColor();

	int i = 0;
	for(; i < _size; i++){
		_window->addText(x + i, y, SPACESHIP_OTHER_CHAR, color);
	}
	_window->addText(x + i, y, SPACESHIP_TOP_CHAR, color);
}

void SpaceShip::setState(unsigned char state){
	_state = state;
}

unsigned char SpaceShip::getState(){
	return _state;
}
