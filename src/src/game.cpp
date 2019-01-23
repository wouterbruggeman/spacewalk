#include "game.h"

Game::Game(){
	//Create a window to draw on
	_window = new Window();

	//Initialze the gamedata struct
	_gameData = new GameData();

	//Fill player data
	_gameData->p1 = new Player(COLOR_BLUE_BLACK, COLOR_BLACK_BLUE, _window);
	_gameData->p2 = new Player(COLOR_GREEN_BLACK, COLOR_BLACK_GREEN, _window);
	_gameData->activePlayer = _gameData->p1;
	//There are 2 players in this game, so every player will be given 4 chips
	_gameData->p1->setChips(4);
	_gameData->p2->setChips(4);

	//Create playerview, location is dependent on the shipview in the placescreen,
	//this will be set later
	_gameData->playerView = new PlayerView(_gameData, _window);
	_gameData->playerView->setSize(PLAYERVIEW_SIZE_X, (_window->getSizeY() / 2) - MARGIN_Y);

	//Create board
	_gameData->board = new Board(_gameData, _window);
	_gameData->board->setLocation(MARGIN_X, _window->getSizeY() / 2);
	_gameData->board->setSize(_window->getSizeX() - (2 * MARGIN_X), (_window->getSizeY() / 2));

	//Initialize the bodies after setting the size and location
	_gameData->board->initBodies();

	//Create screen
	_gameData->currentScreen = new WelcomeScreen(_gameData, _window);
}

Game::~Game(){
	delete _window;
	delete _gameData->p1;
	delete _gameData->p2;
	delete _gameData->activePlayer;
	delete _gameData->playerView;
	delete _gameData->board;
	delete _gameData->currentScreen;
}

void Game::start(){
	_window->start();
	this->draw();
}

void Game::stop(){
	_window->stop();
	_isRunning = false;
}

void Game::loop(){
	this->handleKeyboardInput();
	this->draw();
}

bool Game::isRunning(){
	return _isRunning;
}

void Game::handleKeyboardInput(){
	//Let the screen handle the input
	_gameData->currentScreen->handleInput();
}

void Game::draw(){
	_window->clear();
	_gameData->currentScreen->draw();
	_window->redraw();
}
