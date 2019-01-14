#include "placescreen.h"

PlaceScreen::PlaceScreen(Board *board, Player *p1, Player *p2, Window *window) : Screen(window){
	//Store the pointers
	_board = board;
	_p1 = p1;
	_p2 = p2;

	//Create views
	_shipView = new ShipView(p1, p2, window);
	_playerView = new PlayerView(p1, p2, window);

	//Set view size and location
	_shipView->setSize(SHIPVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_shipView->setLocation(_window->getSizeX() - _shipView->getSizeX() - MARGIN_X, MARGIN_Y);

	_playerView->setSize(PLAYERVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_playerView->setLocation(
		_window->getSizeX() -
		(_shipView->getSizeX() + _playerView->getSizeX() +  2 * MARGIN_X),
		MARGIN_Y
	);

	_board->setLocation(MARGIN_X, _window->getSizeY() / 2);
	_board->setSize(_window->getSizeX() - (2 * MARGIN_X), (_window->getSizeY() / 2));


	//Other setup functions
	_playerView->setActivePlayer(p1);
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

	_board->draw();
	_shipView->draw();
	_playerView->drawMinimal();
}

void PlaceScreen::handleInput(){
	char c = getch();
}
