#include "player.h"

Player::Player(int color, int colorSelected, Window *window)
	: GameObject(window, color, colorSelected){

	//Initialize spaceships
	for(int i = 0; i < 3; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::LARGE,
			this, _window, color, colorSelected);
	}
	for(int i = 3; i < 6; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::MEDIUM,
			this, _window, color, colorSelected);
	}
	for(int i = 6; i < 9; i++){
		_spaceShips[i] = new SpaceShip(SpaceShip::SMALL,
			this, _window, color, colorSelected);
	}
	selectedSpaceShipIndex = 0;
}

Player::~Player(){
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		delete _spaceShips[i];
	}
}

void Player::drawAtPos(int x, int y, bool selected){

}

void Player::setName(string name){
	_name = name;
}

string Player::getName(){
	return _name;
}

SpaceShip* Player::getSpaceShip(int index){
	return _spaceShips[index];
}
