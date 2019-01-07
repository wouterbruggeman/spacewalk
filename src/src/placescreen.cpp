#include "placescreen.h"

PlaceScreen::PlaceScreen(Board *board, Player *p1, Player *p2, Window *window) : Screen(window){
	_board = board;
	_board->setLocation(_window->getSizeX() / 2, _window->getSizeY() / 2);

	_shipSelector = new ShipSelector();
}

/*~PlaceScreen::PlaceScreen(){
	delete _board;
	delete _p1;
	delete _p2;
}*/

void PlaceScreen::draw(){
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO, false);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_NUMBER_ASK, false);

	_board->draw();
	_shipselector->draw();
}
