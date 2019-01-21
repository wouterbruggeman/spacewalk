#include "shipview.h"

ShipView::ShipView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

ShipView::~ShipView(){

}

void ShipView::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);
	_window->addText(x + 2, y + 1, SHIPVIEW_TITLE, COLOR_BLUE_BLACK);

	int selectedIndex = _gameData->activePlayer->getTopUnplacedSpaceShipIndex();

	//Get all ships from this player
	for(int i = 0; i < SPACESHIP_AMOUNT; i++){
		SpaceShip *s = _gameData->activePlayer->getSpaceShip(i);

		//If ship is not placed yet.
		if(s->getState() == SpaceShip::UNPLACED){
			s->drawAtPos(x + 2, y + 3 + i - selectedIndex, (i == selectedIndex));
		}
	}
}

