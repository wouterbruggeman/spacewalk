#include "playerview.h"

PlayerView::PlayerView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void PlayerView::drawMinimal(){
	this->draw();

	//Draw player names
	char *playerName;
	int textColor;

	//Draw player 1
	_gameData->p1->setSelected(_gameData->p1 == _gameData->activePlayer);
	textColor = _gameData->p1->getColor();
	_gameData->p1->getName(playerName);
	_window->addText(_posX + 2, _posY + 3, playerName, textColor);

	//Draw player2
	_gameData->p2->setSelected(_gameData->p2 == _gameData->activePlayer);
	textColor = _gameData->p2->getColor();
	_gameData->p2->getName(playerName);
	_window->addText(_posX + 2, _posY + 4, playerName, textColor);
}

void PlayerView::draw(){
	this->drawBorder();
	//Draw title
	_window->addText(_posX + 2, _posY + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);
}
