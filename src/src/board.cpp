#include "board.h"

Board::Board(Window *window) : GameObject(window){

	//Create planets and black holes.
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		//Every 7th instance is a blackhole
		if((i % 7) == 0){
			_bodies[i] = new BlackHole(_window);
		}else{
			_bodies[i] = new Planet(COLOR_WHITE_BLACK, COLOR_RED_BLACK, _window);
		}
	}
}

Board::~Board(){
	//Delete all the bodies
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		delete _bodies[i];
	}
}

void Board::initBodies(){
	int startX = _posX + (getSizeX() / 4);
	int startY = _posY + (getSizeY() / 2);
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->setLocation(startX + (i * 2 * _bodies[i]->getSizeX()), startY);
	}
	resetSelection();

}

void Board::draw(int x, int y, bool selected){
	this->drawBorder(x, y);

	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->draw();
	}
}

int Board::getSelectedPlanetIndex(){
	//Get selected planet
	int selectedPlanet = 0;

	/*for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		if(Planet *p = dynamic_cast<Planet*>(_bodies[i])){
			if(p->isSelected()){
				selectedPlanet = i;
			}
		}
	}*/
	return selectedPlanet;
}

void Board::moveSelection(bool right){

}

void Board::resetSelection(){
	/*AstronomicalBody *p  = *_bodies;
	p++;
	(Planet) *p = *b;
	p->setSelected(true);*/
}
