#include "playerview.h"

PlayerView::PlayerView(Player *p1, Player *p2, Window *window) : GameObject(window){
	this->_p1 = p1;
	this->_p2 = p2;
}

void PlayerView::drawMinimal(){
	this->draw();

	//Draw player names
	char *playerName;
	int textColor = COLOR_WHITE_BLACK;

	if(this->_p1 == this->_activePlayer){
		textColor = COLOR_BLACK_WHITE;
	}
	this->_p1->getName(playerName);
	_window->addText(_posX + 2, _posY + 3, playerName, textColor);

	textColor = COLOR_WHITE_BLACK;

	if(this->_p2 == this->_activePlayer){
		textColor = COLOR_BLACK_WHITE;
	}
	this->_p2->getName(playerName);
	_window->addText(_posX + 2, _posY + 4, playerName, textColor);
}

void PlayerView::draw(){
	this->drawBorder();
	//Draw title
	_window->addText(_posX + 2, _posY + 1, PLAYERVIEW_TITLE, COLOR_BLUE_BLACK);
}

void PlayerView::setActivePlayer(Player *activePlayer){
	_activePlayer = activePlayer;
}
