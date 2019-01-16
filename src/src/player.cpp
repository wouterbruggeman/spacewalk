#include "player.h"

Player::Player(int color, int colorSelected, Window *window)
	: SelectableObject(color, colorSelected){

	//Store the pointer
	_window = window;

	//Initialize spaceships
	for(int i = 0; i < 3; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::LARGE,
			color, colorSelected, this, _window);
	}
	for(int i = 3; i < 6; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::MEDIUM,
			color, colorSelected, this, _window);
	}
	for(int i = 6; i < 9; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::SMALL,
			color, colorSelected, this, _window);
	}

	_spaceShips[0]->setSelected(true);
}

Player::~Player(){
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		delete _spaceShips[i];
	}
}

void Player::setName(const char *name){
	strcpy(_name, name);
}

void Player::getName(char *str){
	strcpy(str, _name);
}

SpaceShip* Player::getSpaceShip(int index){
	return _spaceShips[index];
}
