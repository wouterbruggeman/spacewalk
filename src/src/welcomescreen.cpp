#include "welcomescreen.h"

void WelcomeScreen::draw(){
	_window->addText(
			_window->getSizeX() / 2,
			_window->getSizeY() / 2,
			WELCOME_MAIN_STR, COLOR_WHITE_BLACK, true
			);
	_window->addText(
			_window->getSizeX() / 2,
			(_window->getSizeY() / 2) + 1,
			WELCOME_SUB_STR, COLOR_WHITE_BLACK, true
			);
	_window->addText(
			_window->getSizeX() - 20,
			_window->getSizeY() - 2,
			INFO_AUTHOR, COLOR_WHITE_BLACK, false
			);
	_window->addText(
			_window->getSizeX() - 20,
			_window->getSizeY() - 1,
			INFO_VERSION, COLOR_WHITE_BLACK, false
			);

}
