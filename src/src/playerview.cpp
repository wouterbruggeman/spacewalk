#include "playerview.h"

PlayerView::PlayerView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void PlayerView::drawMinimal(){
	this->drawBorder(_posX, _posY);
	//Draw player names
	/*char *playerName;
	int textColor;

	//Draw player 1
	textColor = _gameData->p1->getColor(_gameData->p1 == _gameData->activePlayer);
	_gameData->p1->getName(playerName);
	_window->addText(_posX + 2, _posY + 3, playerName, textColor);

	//Draw player2
	textColor = _gameData->p2->getColor(_gameData->p2 == _gameData->activePlayer);
	_gameData->p2->getName(playerName);
	_window->addText(_posX + 2, _posY + 4, playerName, textColor);*/
}

void PlayerView::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);

	//Draw title
	_window->addText(x + 2, y + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);
}
