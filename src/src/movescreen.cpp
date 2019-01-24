#include "movescreen.h"

MoveScreen::MoveScreen(GameData *gameData, Window *window) : Screen(gameData, window){
	//Set playerview location
	_gameData->playerView->setLocation(
		(_window->getSizeX() - _gameData->playerView->getSizeX()) - MARGIN_X,
		MARGIN_Y
	);
	_popup = new Popup(_window);
	_turnPhase = 0;
}

MoveScreen::~MoveScreen(){

}

void MoveScreen::draw(){
	drawStars(100);

	//Draw some info
	_window->addText(MARGIN_X, MARGIN_Y, MOVE_INFO_1);
	_window->addText(MARGIN_X, MARGIN_Y + 1, MOVE_INFO_2);
	_window->addText(MARGIN_X, MARGIN_Y + 2, MOVE_INFO_3);
	_window->addText(MARGIN_X, MARGIN_Y + 3, MOVE_INFO_4);
	_window->addText(MARGIN_X, MARGIN_Y + 4, MOVE_INFO_5);
	_window->addText(MARGIN_X, MARGIN_Y + 5, MOVE_INFO_6);
	_window->addText(MARGIN_X, MARGIN_Y + 6, MOVE_INFO_7);

	//Draw the other elements
	_gameData->board->draw();
	_gameData->playerView->draw();
}

void MoveScreen::handleInput(){
	switch(_turnPhase){
		case MoveScreen::PHASE_BEGIN:
			handleBeginPhase();
			break;
		case MoveScreen::PHASE_SELECTING_PLANET:
			handleSelectingPlanetPhase();
			break;
		case MoveScreen::PHASE_SELECTING_SPACESHIP:
			handleSelectingSpaceShipPhase();
			break;
		case MoveScreen::PHASE_END:
			handleEndPhase();
			break;
		default:
			break;
	}
}

void MoveScreen::handleBeginPhase(){
	if(playerSkipsTurn()){
		//Next player
		nextPlayer();
	}else{
		//Go to the next phase
		_turnPhase = MoveScreen::PHASE_SELECTING_PLANET;
	}
}

void MoveScreen::handleSelectingPlanetPhase(){
	int c = getch();

	//Select a planet with the arrow keys
	if(c == KEY_RIGHT){
		_gameData->board->moveSelection(Board::RIGHT);
	}else if(c == KEY_LEFT){
		_gameData->board->moveSelection(Board::LEFT);
	}else if(c == ' '){
		if(_gameData->board->selectPlanet()){
			checkMoving();
		}
	}
}

void MoveScreen::handleSelectingSpaceShipPhase(){
	int c = getch();

	//Select a spaceship with the arrow keys
	if(c == KEY_UP){
		_gameData->board->moveSelection(Board::UP);
	}else if(c == KEY_DOWN){
		_gameData->board->moveSelection(Board::DOWN);
	}else if(c == ' '){
		_gameData->board->moveSelectedSpaceShip();
		checkMoving();
	}
}

void MoveScreen::checkMoving(){
	//No more ships left?
	if(!_gameData->board->hasUnmovedSpaceShips()){
		_turnPhase = MoveScreen::PHASE_END;
		return;
	}
	//player must select spaceship?
	if(_gameData->board->playerMustSelectSpaceShip()){
		//Initialize the selection
		_gameData->board->initSpaceShipSelection();

		//Go to the selecting phase
		_turnPhase = MoveScreen::PHASE_SELECTING_SPACESHIP;
		return;
	}
	_gameData->board->moveSpaceShipsFromSelectedPlanet();
	checkMoving();
}

void MoveScreen::handleEndPhase(){
	//TODO: Ask if the player would like to get a new turn
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
	_turnPhase = MoveScreen::PHASE_BEGIN;
}
