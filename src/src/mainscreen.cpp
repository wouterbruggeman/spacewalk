#include "mainscreen.h"

MainScreen::MainScreen(Window *window) : Screen(window){

}

void MainScreen::draw(){
	_window->clear();

	_window->addText(
			_window->getSizeX() / 2,
			_window->getSizeY() / 2,
			"---", true
			);
	_window->addText(
			_window->getSizeX() / 2,
			(_window->getSizeY() / 2) + 1,
			"Placeholder", true
			);
}
