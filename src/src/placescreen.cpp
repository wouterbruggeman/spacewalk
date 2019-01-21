#include "placescreen.h"

PlaceScreen::PlaceScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	//Create ship view, playerview is already created.
	_shipView = new ShipView(_gameData, window);

	//Set shipview size and location
	_shipView->setSize(SHIPVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_shipView->setLocation(_window->getSizeX() - _shipView->getSizeX() - MARGIN_X, MARGIN_Y);

	//Set playerview size and location
	_gameData->playerView->setSize(PLAYERVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_gameData->playerView->setLocation(
		_window->getSizeX() -
		(_shipView->getSizeX() + _gameData->playerView->getSizeX() +  2 * MARGIN_X),
		MARGIN_Y
	);

	//Create board.
	_gameData->board->setLocation(MARGIN_X, _window->getSizeY() / 2);
	_gameData->board->setSize(_window->getSizeX() - (2 * MARGIN_X), (_window->getSizeY() / 2));

	//Initialize the bodies after setting the size and location
	_gameData->board->initBodies();
}

PlaceScreen::~PlaceScreen(){
	delete _shipView;
}

void PlaceScreen::draw(){
	//Draw some info
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO_1);
	_window->addText(MARGIN_X, MARGIN_Y+1, PLACE_INFO_2);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_INFO_3);
	_window->addText(MARGIN_X, MARGIN_Y+3, PLACE_INFO_4);
	_window->addText(MARGIN_X, MARGIN_Y+4, PLACE_INFO_5);

	//Draw the other elements
	_gameData->board->draw();
	_shipView->draw();
	_gameData->playerView->draw();
}

void PlaceScreen::handleInput(){
	int c = getch();

	//Select and place the boards
	if(c == KEY_RIGHT){
		_gameData->board->moveSelection(true);
	}else if(c == KEY_LEFT){
		_gameData->board->moveSelection(false);
	}else if(c == KEY_ENTER){

	}
}
