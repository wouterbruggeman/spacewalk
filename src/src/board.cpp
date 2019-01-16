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
	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->setLocation(_posX + 3 + (i * 2 * _bodies[i]->getSizeX()), _posY + 1);
	}

}

void Board::draw(){
	this->drawBorder();

	for(int i = 0; i < AMOUNT_OF_BODIES; i++){
		_bodies[i]->draw();
	}
}
