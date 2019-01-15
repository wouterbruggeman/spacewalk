#include "player.h"

Player::Player(Window *window){
	//Store the pointer
	_window = window;

	//Initialize spaceships
	for(int i = 0; i < MAX_SPACESHIP_AMOUNT; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::LARGE, this, _window);
	}
}

Player::~Player(){
	for(int i = 0; i < MAX_SPACESHIP_AMOUNT; i++){
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
