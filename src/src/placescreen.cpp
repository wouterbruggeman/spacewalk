#include "placescreen.h"

PlaceScreen::PlaceScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	//Create views
	_shipView = new ShipView(_gameData->p1, _gameData->p2, window);
	_playerView = new PlayerView(gameData->p1, _gameData->p2, window);

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
}

PlaceScreen::~PlaceScreen(){
	delete _shipView;
	delete _playerView;
}

void PlaceScreen::draw(){
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO_1, false);
	_window->addText(MARGIN_X, MARGIN_Y+1, PLACE_INFO_2, false);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_INFO_3, false);
	_window->addText(MARGIN_X, _window->getSizeY() / 2 -1, PLACE_NUMBER_ASK, false);

	_gameData->board->draw();
	_shipView->draw();
	_playerView->drawMinimal();
}

void PlaceScreen::handleInput(){
	char c = getch();
}
