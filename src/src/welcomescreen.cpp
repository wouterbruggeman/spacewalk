#include "welcomescreen.h"

WelcomeScreen::WelcomeScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	_popup = new Popup(_window);
}

WelcomeScreen::~WelcomeScreen(){
	delete _popup;
}

void WelcomeScreen::draw(){
	//Draw stars
	drawStars(100);

	//Draw main text
	_window->addText(
		_window->getSizeX() / 2,
		_window->getSizeY() / 2,
		WELCOME_MAIN, COLOR_WHITE_BLACK, true
		);
	_window->addText(
		_window->getSizeX() / 2,
		(_window->getSizeY() / 2) + 1,
		CONTINUE_INFO, COLOR_WHITE_BLACK, true
		);

	//Draw author name and version
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

void WelcomeScreen::handleInput(){
	char c = getch();
	if(c == ' '){
		//Ask the name for player 1
		_popup->setMessage(WELCOME_ENTER_NAME_1);
		_popup->draw();
		_gameData->p1->setName(_popup->getString());

		//Ask the name for player 2
		_popup->setMessage(WELCOME_ENTER_NAME_2);
		_popup->draw();
		_gameData->p2->setName(_popup->getString());

		this->nextScreen();

	}
}

void WelcomeScreen::nextScreen(){
	//Switch the screen
	_gameData->currentScreen = new PlaceScreen(_gameData, _window);
	delete this;
}
