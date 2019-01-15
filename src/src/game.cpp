#include "game.h"

Game::Game(){
	//Create a window to draw on
	_window = new Window();

	//Initialze the gamedata struct
	_gameData = new GameData();
	_gameData->p1 = new Player(_window);
	_gameData->p2 = new Player(_window);
	_gameData->activePlayer = _gameData->p1;
	_gameData->board = new Board(_window);
	_gameData->currentScreen = new WelcomeScreen(_gameData, _window);
}

Game::~Game(){
	delete _window;
	delete _gameData;
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
