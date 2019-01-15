#include "player.h"

Player::Player(Window *window){
	//Store the pointer
	_window = window;

	//Initialize spaceships
	for(int i = 0; i < MAX_SPACESHIP_AMOUNT; i++){
		this->_spaceShips[i] = new SpaceShip(SpaceShip::LARGE, this, this->_window);
	}
}

Player::~Player(){
	//TOOD: forloop to delete each spaceship
}

void Player::setName(const char *name){
	strcpy(_name, name);
}

void Player::getName(char *str){
	strcpy(str, _name);
}
