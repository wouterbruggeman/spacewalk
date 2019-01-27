#include "board.h"

Board::Board(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

Board::~Board(){
	//Delete all the bodies
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		delete _bodies[i];
	}
}

void Board::initBodies(){
	//Position variables
	int startX = _posX + (getSizeX() / 4);
	int startY = _posY + (getSizeY() / 2);

	//Create planets and black holes.
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		//Every 7th instance is a blackhole
		if(bodyIsPlanet(i)){
			_bodies[i] = new Planet(COLOR_WHITE_BLACK, COLOR_RED_BLACK, _window);
		}else{
			_bodies[i] = new BlackHole(_window);
		}
		//Set the location for the instance
		_bodies[i]->setLocation(startX + (i * 2 * _bodies[i]->getSizeX()), startY);
	}

	//Reset to initialize
	_movedShips = 0;
	resetSelection();
}

void Board::resetSelection(){
	_selectedBodyIndex = 1;
}

void Board::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x, y);
	_window->addText(x + MARGIN_X, y + MARGIN_Y, _statusMessage);

	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->draw(_selectedBodyIndex == i);
	}
}

void Board::setStatusMessage(string message){
	_statusMessage = message;
}

void Board::moveSelection(int direction){
	if(direction == Board::RIGHT){
		_selectedBodyIndex = getNextPlanetIndex(_selectedBodyIndex);
		_selectedSpaceShipIndex = -1;

	}else if(direction == Board::LEFT){
		_selectedBodyIndex = getPreviousPlanetIndex(_selectedBodyIndex);
		_selectedSpaceShipIndex = -1;

	}else if(direction == Board::UP){
		//Get the selected Body which is always a planet
		Planet *p = (Planet*) _bodies[_selectedBodyIndex];

		//If the other ship is in range and size equals
		if(
			(_selectedSpaceShipIndex < p->getSpaceShipsCount() - 1)
			&& (p->getSpaceShip(_selectedSpaceShipIndex + 1)->sizeEquals(
				p->getSpaceShip(_selectedSpaceShipIndex)))
		  ){
			_selectedSpaceShipIndex++;
		}
	}else if(direction == Board::DOWN){
		//Get the selected Body which is always a planet
		Planet *p = (Planet*) _bodies[_selectedBodyIndex];

		//If the 2 spaceships are equal and in range
		if(
			(_selectedSpaceShipIndex > 0)
			&& (p->getSpaceShip(_selectedSpaceShipIndex - 1)->sizeEquals(
				p->getSpaceShip(_selectedSpaceShipIndex)))
		  ){
			_selectedSpaceShipIndex--;
		}
	}
	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];
	p->selectSpaceShip(_selectedSpaceShipIndex);
}

bool Board::placeSpaceShip(int index){
	SpaceShip *s = _gameData->activePlayer->getSpaceShip(index);

	//Body is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];
	if(p->addSpaceShip(s, true)){
		//Ship was placed
		s->setState(SpaceShip::PLACED);
		return true;
	}else{
		//Ship could not be placed
		setStatusMessage((string)PLACE_FAIL + (string)SELECT_OTHER_PLANET);
		return false;
	}
}

bool Board::playerMustSelectSpaceShip(){
	return (getAmountOfSameSizedSpaceShips() > 1);
}

void Board::initSpaceShipSelection(){
	//Set index to starting value
	_selectedSpaceShipIndex = 0;

	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];

	//Show the selection
	p->selectSpaceShip(_selectedSpaceShipIndex);
}

bool Board::selectPlanet(){
	//Reset the moved ships counter
	_movedShips = 0;

	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];

	//If the planet does not contain spaceships:
	if(!p->containsSpaceShips()){
		setStatusMessage((string)SELECT_FAIL_SHIPS + (string)SELECT_OTHER_PLANET);
		return false;
	}
	//If the planet does not contain ships where the owner is the player
	if(!p->containsSpaceShipsOfPlayer(_gameData->activePlayer)){
		setStatusMessage((string)SELECT_FAIL_PLAYER + (string)SELECT_OTHER_PLANET);
		return false;
	}
	return true;
}

bool Board::hasUnmovedSpaceShips(){
	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];

	return (p->containsSpaceShips());
}

int Board::getAmountOfSameSizedSpaceShips(){
	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];

	//Biggest spaceship is always at index 0
	int size = p->getSpaceShip(0)->getSize();
	int count = 0;

	for(int i = 0; i < p->getSpaceShipsCount(); i++){
		if(p->getSpaceShip(i)->getSize() == size){
			//If its the same size, increment the counter
			count++;
		}else{
			//Other spaceship found. Return the counter
			return count;
		}
	}
	//Return 0 if the loop did not start
	return count;
}

void Board::moveSpaceShipsFromSelectedPlanet(){
	moveSpaceShip(0);
}

void Board::moveSelectedSpaceShip(){
	moveSpaceShip(_selectedSpaceShipIndex);

	//Reset the selected index
	_selectedSpaceShipIndex = -1;
}

void Board::moveSpaceShip(int index){
	//Get the current planet
	Planet *p = (Planet*) _bodies[_selectedBodyIndex];

	//Find the next body
	int nextIndex = calculateBodyIndex(_selectedBodyIndex + ++_movedShips);

	//If the next body is a planet
	if(bodyIsPlanet(nextIndex)){
		//Get the next planet
		Planet *nextPlanet = (Planet*) _bodies[nextIndex];

		//Add the spaceship to the planet
		nextPlanet->addSpaceShip(p->getSpaceShip(index), false);
	}else{
		//Next body is a blackhole.

		//Set the spaceship status to destroyed
		p->getSpaceShip(index)->setState(SpaceShip::DESTROYED);
	}

	//Remove the spaceship from the current planet
	p->removeSpaceShip(index);
	p->selectSpaceShip(-1);
}

bool Board::bodyIsPlanet(int index){
	return ((index % 7) != 0);
}

int Board::calculateBodyIndex(int index){
	int ret = index % AMOUNT_OF_BODIES;
	if(ret < 0){
		ret+=AMOUNT_OF_BODIES;
	}
	return ret;

}

int Board::getNextPlanetIndex(int index){
	index = calculateBodyIndex(++index);
	if(!bodyIsPlanet(index)){
		return getNextPlanetIndex(index);
	}
	return index;
}

int Board::getPreviousPlanetIndex(int index){
	index = calculateBodyIndex(--index);
	if(!bodyIsPlanet(index)){
		return getPreviousPlanetIndex(index);
	}
	return index;
}
