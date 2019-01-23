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

	_chips = 0;
}

Player::~Player(){
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		delete _spaceShips[i];
	}
}

void Player::drawAtPos(int x, int y, bool selected){
	//Draw name
	_window->addText(x, y, this->getName(), this->getColor(selected));

	//Draw amount of chips
	_window->addText(x + 1, y + 1, PLAYER_DRAW_CHIPS + to_string(this->getChips()));
}

void Player::setName(string name){
	_name = name;
}

string Player::getName(){
	return _name;
}

void Player::setChips(int amount){
	_chips = amount;
}

int Player::getChips(){
	return _chips;
}

SpaceShip* Player::getSpaceShip(int index){
	return _spaceShips[index];
}

int Player::getTopUnplacedSpaceShipIndex(){
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		//If ship is not placed yet.
		if(_spaceShips[i]->getState() == SpaceShip::UNPLACED){
			//Return the first unplaced ship index
			return i;
		}
	}
	return -1;
}
