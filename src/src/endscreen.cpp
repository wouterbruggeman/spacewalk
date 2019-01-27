#include "endscreen.h"

EndScreen::EndScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	_status = -1;
	_popup = new Popup(_window);
}

EndScreen::~EndScreen(){
	delete _popup;
}

void EndScreen::draw(){
	//Draw stars
	drawStars(100);

	//Draw main text
	_window->addText(
		_window->getSizeX() / 2,
		_window->getSizeY() / 2 - 4,
		END_MAIN_1 + _gameData->activePlayer->getName() + END_MAIN_2,
		COLOR_WHITE_BLACK, true
	);
	//Draw score
	_window->addText(
		_window->getSizeX() / 2,
		_window->getSizeY() / 2 - 2,
		END_SCORE_1 + to_string(_gameData->activePlayer->getScore()),
		COLOR_WHITE_BLACK, true
	);


	//Draw all spaceships
	_window->addText(
		_window->getSizeX() / 2,
		_window->getSizeY() / 2 - 1,
		END_SCORE_2 + to_string(
			SPACESHIP_AMOUNT -
			_gameData->activePlayer->getTotalDestroyedSpaceShips()
			),
		COLOR_WHITE_BLACK, true
	);


	_window->addText(
		_window->getSizeX() / 2,
		(_window->getSizeY() / 2 + 1),
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

void EndScreen::handleInput(){
	char c = getch();

	if(c == ' '){
		//Ask for a new game
		_popup->setMessage(NEW_GAME_QUESTION);

		//Save the answer
		_status = _popup->getBool();
	}
}

void EndScreen::nextScreen(){

}

int EndScreen::getStatus(){
	return _status;
}
