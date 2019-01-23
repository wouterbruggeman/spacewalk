#include "movescreen.h"

MoveScreen::MoveScreen(GameData *gameData, Window *window) : Screen(gameData, window){
	//Set playerview location
	_gameData->playerView->setLocation(
		(_window->getSizeX() - _gameData->playerView->getSizeX()) - MARGIN_X,
		MARGIN_Y
	);
	_popup = new Popup(_window);
}

MoveScreen::~MoveScreen(){

}

void MoveScreen::draw(){
	drawStars(100);

	//Draw some info
	_window->addText(MARGIN_X, MARGIN_Y, MOVE_INFO_1);

	//Draw the other elements
	_gameData->board->draw();
	_gameData->playerView->draw();
}

void MoveScreen::handleInput(){
	if(playerSkipsTurn()){
		//Next player
		nextPlayer();

		//Do not ask for more input if the player decides to skip his turn
		return;
	}

	//Ask for more input
	int c = getch();

	//Select and place the boards
	if(c == KEY_RIGHT){
		_gameData->board->moveSelection(true);
	}else if(c == KEY_LEFT){
		_gameData->board->moveSelection(false);
	}else if(c == ' '){
		//_gameData->board->grabSpaceShips();
	}

	nextPlayer();
}

bool MoveScreen::playerSkipsTurn(){
	_popup->setMessage(PLAYER_OPTIONS_SKIP_1, 0);
	_popup->setMessage(
		PLAYER_OPTIONS_SKIP_2 + to_string(_gameData->activePlayer->getChips()) +
		PLAYER_OPTIONS_SKIP_3, 1);

	//Get amount of chips
	int chips = _gameData->activePlayer->getChips();

	//If the player does not have enough chips to skip his turn
	if(chips == 0){
		return false;
	}

	//If the player wants to skip his turn.
	if(_popup->getBool()){
		//Decrement the amount of chips the player has.
		_gameData->activePlayer->setChips(--chips);
		return true;
	}

	return false;
}

void MoveScreen::nextScreen(){

}

void MoveScreen::nextPlayer(){
	Screen::nextPlayer();
	_gameData->board->setStatusMessage(YOUR_TURN + _gameData->activePlayer->getName());
}
