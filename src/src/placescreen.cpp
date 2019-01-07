#include "placescreen.h"

PlaceScreen::PlaceScreen(Window *window) : Screen(window){
	_board = new Board(_window);
	_board->setLocation(_window->getSizeX() / 2, _window->getSizeY() / 2);
}

/*~PlaceScreen::PlaceScreen(){
	delete board;
}*/

void PlaceScreen::draw(){
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO, false);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_NUMBER_ASK, false);

	_board->draw();
}
