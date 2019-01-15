#include "welcomescreen.h"

WelcomeScreen::WelcomeScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){
}

WelcomeScreen::~WelcomeScreen(){
	delete _nameInput;
	//NameInput is already deleted at this point
}

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

	//If the nameinput object exists, ask for input
	if(_nameInput != nullptr){
		//Ask the name for player 1
		_nameInput->setMessage(WELCOME_ENTER_NAME_1);
		_nameInput->draw();
		_gameData->p1->setName(_nameInput->getString());

		//Ask the name for player 2
		_nameInput->setMessage(WELCOME_ENTER_NAME_2);
		_nameInput->draw();
		_gameData->p2->setName(_nameInput->getString());

		delete _nameInput;
		this->nextScreen();
	}
}

void WelcomeScreen::handleInput(){
	char c = getch();

	if(c == ' '){
		//Ask for the usernames
		_nameInput = new NameInput(_window);
		this->draw();
	}
}

void WelcomeScreen::nextScreen(){
	_gameData->currentScreen = new PlaceScreen(_gameData, _window);
}
