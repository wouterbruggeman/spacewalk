#include "playerview.h"

PlayerView::PlayerView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void PlayerView::drawMinimal(){
	this->draw();

	//Draw player names
	char *playerName;
	int textColor = COLOR_WHITE_BLACK;

	//Check player 1
	if(_gameData->p1 == _gameData->activePlayer){
		textColor = COLOR_BLACK_WHITE;
	}
	_gameData->p1->getName(playerName);
	_window->addText(_posX + 2, _posY + 3, playerName, textColor);

	//reset color
	textColor = COLOR_WHITE_BLACK;

	//Check player2
	if(_gameData->p2 == _gameData->activePlayer){
		textColor = COLOR_BLACK_WHITE;
	}
	_gameData->p2->getName(playerName);
	_window->addText(_posX + 2, _posY + 4, playerName, textColor);
}

void PlayerView::draw(){
	this->drawBorder();
	//Draw title
	_window->addText(_posX + 2, _posY + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);
}
