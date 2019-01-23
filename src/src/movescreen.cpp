#include "movescreen.h"

MoveScreen::MoveScreen(GameData *gameData, Window *window) : Screen(gameData, window){
	//Set playerview location
	_gameData->playerView->setLocation(
		(_window->getSizeX() - _gameData->playerView->getSizeX()) - MARGIN_X,
		MARGIN_Y
	);
	_popup = new Popup(_window);
	_popup->setMessage(PLAYER_OPTIONS_SKIP);
}

MoveScreen::~MoveScreen(){

}

void MoveScreen::draw(){
	drawStars(100);

	//Draw some info
	_window->addText(MARGIN_X, MARGIN_Y, MOVE_INFO_1);

	//Draw the other elements
	_gameData->board->draw();
	_gameData->playerView->draw();
}

void MoveScreen::handleInput(){
	_popup->getBool();
	//char c = getch();
}
