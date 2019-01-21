#include "board.h"

Board::Board(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;

	_placeStatus = -1;
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

	//First item is selected
	_selectedBody = 1;
}

void Board::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x, y);
	if(_placeStatus){
	//	_window->addText(x + MARGIN_X, y + MARGIN_Y, _statusMessage);
	}else{

	}

	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->draw(_selectedBody == i);
	}
}

void Board::moveSelection(bool right){
	if(right){
		_selectedBody++;
		if((_selectedBody % 7) == 0){
			_selectedBody++;
		}
		if(_selectedBody > AMOUNT_OF_BODIES){
			_selectedBody = 1;
		}
	}else{
		_selectedBody--;
		if((_selectedBody % 7) == 0){
			_selectedBody--;
		}
		if(_selectedBody < 0){
			_selectedBody = AMOUNT_OF_BODIES - 1;
		}
	}
}

void Board::placeSpaceShip(){
	//Loop through all spaceships and find the unselected ones.
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		SpaceShip *s = _gameData->activePlayer->getSpaceShip(i);
		//If ship is not placed yet.
		if(s->getState() == SpaceShip::UNPLACED){
			//Body is always a planet
			Planet *p = (Planet*) _bodies[_selectedBody];
			_placeStatus = p->addSpaceShip(s);

			//If the ship was placed
			if(_placeStatus){
				s->setState(SpaceShip::PLACED);
			}
			return;
		}
	}
}
