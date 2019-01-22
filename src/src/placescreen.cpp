#include "placescreen.h"

PlaceScreen::PlaceScreen(GameData *gameData, Window *window)
	: Screen(gameData, window){

	//Create ship view, playerview is already created.
	_shipView = new ShipView(_gameData, window);

	//Set shipview size and location
	_shipView->setSize(SHIPVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);
	_shipView->setLocation(_window->getSizeX() - _shipView->getSizeX() - MARGIN_X, MARGIN_Y);

	//Set playerview location
	_gameData->playerView->setLocation(
		_window->getSizeX() -
		(_shipView->getSizeX() + _gameData->playerView->getSizeX() +  2 * MARGIN_X),
		MARGIN_Y
	);
}

PlaceScreen::~PlaceScreen(){
	delete _shipView;
}

void PlaceScreen::draw(){
	//Draw stars
	drawStars(100);

	//Draw some info
	_window->addText(MARGIN_X, MARGIN_Y, PLACE_INFO_1);
	_window->addText(MARGIN_X, MARGIN_Y+1, PLACE_INFO_2);
	_window->addText(MARGIN_X, MARGIN_Y+2, PLACE_INFO_3);
	_window->addText(MARGIN_X, MARGIN_Y+3, PLACE_INFO_4);
	_window->addText(MARGIN_X, MARGIN_Y+4, PLACE_INFO_5);

	//Draw the other elements
	_gameData->board->draw();
	_shipView->draw();
	_gameData->playerView->draw();
}

void PlaceScreen::handleInput(){
	int c = getch();

	//Select and place the boards
	if(c == KEY_RIGHT){
		_gameData->board->moveSelection(true);
	}else if(c == KEY_LEFT){
		_gameData->board->moveSelection(false);
	}else if(c == ' '){
		placeSpaceShipOnBoard();
	}
}

void PlaceScreen::placeSpaceShipOnBoard(){
	//Get the index of the top unplaced spaceship
	int shipIndex = _gameData->activePlayer->getTopUnplacedSpaceShipIndex();

	//If there is no unplaced ship left
	if(shipIndex == -1){
		//Check if we need to switch to the next screen.
		if(_gameData->activePlayer == _gameData->p2){
			nextScreen();
			return;
		}
		switchPlayer();
		return;
	}

	//Place the ship
	if(_gameData->board->placeSpaceShip(shipIndex)){
		switchPlayer();
	}
}

void PlaceScreen::nextScreen(){
	_gameData->currentScreen = new MoveScreen(_gameData, _window);
}

void PlaceScreen::switchPlayer(){
	if(_gameData->activePlayer == _gameData->p1){
		_gameData->activePlayer = _gameData->p2;
	}else{
		_gameData->activePlayer = _gameData->p1;
	}
	_gameData->board->setStatusMessage(YOUR_TURN + _gameData->activePlayer->getName());
}
