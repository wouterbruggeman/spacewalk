#include "placescreen.h"

PlaceScreen::PlaceScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	//Create views
	_shipView = new ShipView(_gameData, window);
	_playerView = new PlayerView(_gameData, window);
	//TODO: Move playerview to gamedata object

	//Set view size and location
	_shipView->setSize(SHIPVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_shipView->setLocation(_window->getSizeX() - _shipView->getSizeX() - MARGIN_X, MARGIN_Y);

	_playerView->setSize(PLAYERVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_playerView->setLocation(
		_window->getSizeX() -
		(_shipView->getSizeX() + _playerView->getSizeX() +  2 * MARGIN_X),
		MARGIN_Y
	);

	_gameData->board->setLocation(MARGIN_X, _window->getSizeY() / 2);
	_gameData->board->setSize(_window->getSizeX() - (2 * MARGIN_X), (_window->getSizeY() / 2));

	_gameData->board->initBodies();
}

PlaceScreen::~PlaceScreen(){
	delete _shipView;
	delete _playerView;
}

void PlaceScreen::draw(){
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO_1, false);
	_window->addText(MARGIN_X, MARGIN_Y+1, PLACE_INFO_2, false);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_INFO_3, false);
	_window->addText(MARGIN_X, MARGIN_Y+3, PLACE_INFO_4, false);
	_window->addText(MARGIN_X, MARGIN_Y+4, PLACE_INFO_5, false);

	_gameData->board->draw();
	_shipView->draw();
	_playerView->draw();
}

void PlaceScreen::handleInput(){
	char c = getch();

	if(c == KEY_RIGHT){
		_gameData->board->moveSelection(true);
	}
}
