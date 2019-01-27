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
	_window->addText(x, y + 1, (string)INDENT_2 +
		(string)PLAYER_DRAW_CHIPS + to_string(this->getChips()));

	//Draw empty line
	_window->addText(x, y + 2, (string)INDENT_1);

	//Draw amount of spaceships
	_window->addText(x, y + 3, (string)INDENT_2 +
		(string)PLAYER_DRAW_SHIPS);

	_window->addText(x + 2, y + 4, (string)INDENT_2 + (string)PLAYER_DRAW_SHIPS_TOTAL +
		to_string(SPACESHIP_AMOUNT));

	_window->addText(x + 2, y + 5, (string)INDENT_2 + (string)PLAYER_DRAW_SHIPS_DESTROYED +
		to_string(this->getTotalDestroyedSpaceShips()));
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

int Player::getTotalDestroyedSpaceShips(){
	int total = 0;
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		if(_spaceShips[i]->getState() == SpaceShip::DESTROYED){
			total++;
		}
	}
	return total;
}

int Player::getScore(){
	int score = 0;

	//If there are chips:
	if(getChips() > 0){
		score += 2;
	}

	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		if(_spaceShips[i]->getState() == SpaceShip::PLACED){
			score += _spaceShips[i]->getSize();
		}
	}
	return score;
}
