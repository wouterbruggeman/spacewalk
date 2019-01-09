#include "placescreen.h"

PlaceScreen::PlaceScreen(Board *board, Player *p1, Player *p2, Window *window) : Screen(window){
	_shipView = new ShipView(p1, p2, window);
	_shipView->setSize(SHIPVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_X);
	_shipView->setLocation(_window->getSizeX() - _shipView->getSizeX() - MARGIN_X, MARGIN_Y);

	_board = board;
	_board->setLocation(MARGIN_X, _window->getSizeY() / 2);
	_board->setSize(_window->getSizeX() - (2 * MARGIN_X), (_window->getSizeY() / 2));

	/*_shipSelector = new ShipSelector();
	_shipSelector->*/
	//REPLACE WITH SHIP VIEW
}

PlaceScreen::~PlaceScreen(){
	delete _shipView;
}

void PlaceScreen::draw(){
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO, false);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_NUMBER_ASK, false);

	_board->draw();
	_shipView->draw();
}
