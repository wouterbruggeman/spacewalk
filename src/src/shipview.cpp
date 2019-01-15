#include "shipview.h"

ShipView::ShipView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void ShipView::draw(){
	this->drawBorder();
	_window->addText(_posX + 2, _posY + 1, SHIPVIEW_TITLE, COLOR_BLUE_BLACK);

	//Get all ships from this player
	for(int i = 0; i < MAX_SPACESHIP_AMOUNT; i++){
		SpaceShip *s = _gameData->activePlayer->getSpaceShip(i);
		//If ship is not destroyed
		if(!s->isDestroyed()){
			//Draw the spaceship
			s->draw(_posX + 2, _posY + 3 + i, (i==0));
		}
	}
}
