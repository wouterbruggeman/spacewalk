#include "welcomescreen.h"

void WelcomeScreen::draw(){
	_window->clear();

	_window->addText(
			_window->getSizeX() / 2,
			_window->getSizeY() / 2,
			WELCOME_MAIN_STR, true
			);
	_window->addText(
			_window->getSizeX() / 2,
			(_window->getSizeY() / 2) + 1,
			WELCOME_SUB_STR, true
			);
}
