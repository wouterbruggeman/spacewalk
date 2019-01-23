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
		if((i % 7) == 0){
			_bodies[i] = new BlackHole(_window);
		}else{
			_bodies[i] = new Planet(COLOR_WHITE_BLACK, COLOR_RED_BLACK, _window);
		}
		//Set the location for the instance
		_bodies[i]->setLocation(startX + (i * 2 * _bodies[i]->getSizeX()), startY);
	}

	//Reset to initialize
	resetSelection();
}

void Board::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x, y);
	_window->addText(x + MARGIN_X, y + MARGIN_Y, _statusMessage);

	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->draw(_selectedBody == i);
	}
}

void Board::setStatusMessage(string message){
	_statusMessage = message;
}

void Board::moveSelection(int direction){
	if(direction == Board::RIGHT){
		_selectedBody++;
		if((_selectedBody % 7) == 0){
			_selectedBody++;
		}
		if(_selectedBody > AMOUNT_OF_BODIES){
			_selectedBody = 1;
		}
		_selectedSpaceShipIndex = -1;

	}else if(direction == Board::LEFT){
		_selectedBody--;
		if((_selectedBody % 7) == 0){
			_selectedBody--;
		}
		if(_selectedBody < 0){
			_selectedBody = AMOUNT_OF_BODIES - 1;
		}
		_selectedSpaceShipIndex = -1;

	}else if(direction == Board::UP){

		//If the other ship is in range and size equals
		if((_selectedSpaceShipIndex < _grabbedSpaceShips.size() - 1)
			&& (_grabbedSpaceShips[_selectedSpaceShipIndex + 1]->sizeEquals(
				_grabbedSpaceShips[_selectedSpaceShipIndex])))
		{
			_selectedSpaceShipIndex++;
		}


	}else if(direction == Board::DOWN){
		//If the 2 spaceships are equal and in range
		if((_selectedSpaceShipIndex > 0)
			&& (_grabbedSpaceShips[_selectedSpaceShipIndex - 1]->sizeEquals(
				_grabbedSpaceShips[_selectedSpaceShipIndex])))
		{
			_selectedSpaceShipIndex--;
		}
	}
	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBody];
	p->selectSpaceShip(_selectedSpaceShipIndex);

}

bool Board::placeSpaceShip(int index){
	SpaceShip *s = _gameData->activePlayer->getSpaceShip(index);

	//Body is always a planet
	Planet *p = (Planet*) _bodies[_selectedBody];
	if(p->addSpaceShip(s)){
		//Ship was placed
		s->setState(SpaceShip::PLACED);
		return true;
	}else{
		//Ship could not be placed
		setStatusMessage(PLACE_FAIL);
		return false;
	}
}

bool Board::grabSpaceShips(){
	//Get the selected Body which is always a planet
	Planet *p = (Planet*) _bodies[_selectedBody];

	//If the planet contains spaceships:
	if(!p->containsSpaceShips()){
		setStatusMessage(GRAB_FAIL);
		return false;
	}

	//Select the first spaceship.
	_selectedSpaceShipIndex = 0;
	p->selectSpaceShip(_selectedSpaceShipIndex);

	_grabbedSpaceShips = p->getSpaceShips();
	setStatusMessage(GRAB_SUCCESS);

	return true;
}

void Board::moveGrabbedShips(){
	Planet *p = (Planet*) _bodies[_selectedBody];

	//Reset the index
	resetSelection();

}

void Board::resetSelection(){
	_selectedBody = 1;
	_selectedSpaceShipIndex = -1;
}
