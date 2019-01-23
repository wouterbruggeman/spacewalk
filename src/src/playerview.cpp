#include "playerview.h"

PlayerView::PlayerView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void PlayerView::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);

	//Draw title
	_window->addText(x + 2, y + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);

	//Draw player 1
	_gameData->p1->draw(_gameData->p1 == _gameData->activePlayer);

	//Draw player2
	_gameData->p2->draw(_gameData->p2 == _gameData->activePlayer);
}

void PlayerView::setLocation(int x, int y){
	_posX = x;
	_posY = y;

	//Update the positions of the players
	_gameData->p1->setLocation(_posX + 2, _posY + 3);
	_gameData->p2->setLocation(_posX + 2, _posY + 10);
}
