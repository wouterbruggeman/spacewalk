#include "playerview.h"

PlayerView::PlayerView(GameData *gameData, Window *window) : GameObject(window){
	_gameData = gameData;
}

void PlayerView::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);

	//Draw title
	_window->addText(x + 2, y + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);

	int textColor;

	//Draw player 1
	textColor = _gameData->p1->getColor(_gameData->p1 == _gameData->activePlayer);
	_window->addText(_posX + 2, _posY + 3, _gameData->p1->getName(), textColor);

	//Draw player2
	textColor = _gameData->p2->getColor(_gameData->p2 == _gameData->activePlayer);
	_window->addText(_posX + 2, _posY + 4, _gameData->p2->getName(), textColor);

}
