#include "game.h"

Game::Game(){
	_window = new Window();

	_board = new Board(_window);
	_p1 = new Player();
	_p2 = new Player();

	_welcomeScreen = new WelcomeScreen(_p1, _p2, _window);
	_placeScreen = new PlaceScreen(_board, _p1, _p2, _window);
	_mainScreen = new MainScreen(_window);

	_gamePhrase = 0;
}

Game::~Game(){
	delete _window;

	delete _welcomeScreen;
	delete _placeScreen;
	delete _mainScreen;

	delete _p1;
	delete _p2;
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
	this->handleGamePhrases();
	this->draw();
}

bool Game::isRunning(){
	return _isRunning;
}

void Game::handleKeyboardInput(){
	//Let the screen handle the input
	switch (_gamePhrase){
		case 0:
			_welcomeScreen->handleInput();
			break;
		case 1:
			_placeScreen->handleInput();
			break;
		case 2:
			_mainScreen->handleInput();
			break;
	}
}

void Game::handleGamePhrases(){
	if((_gamePhrase == 0) && _welcomeScreen->isReady()){
		_gamePhrase++;
	}else if((_gamePhrase == 1) && _placeScreen->isReady()){
		_gamePhrase++;
	}else if((_gamePhrase == 2) && _mainScreen->isReady()){
		_gamePhrase++;
	}
}

void Game::draw(){
	_window->clear();

	switch (_gamePhrase){
		case 0:
			_welcomeScreen->draw();
			break;
		case 1:
			_placeScreen->draw();
			break;
		case 2:
			_mainScreen->draw();
			break;
	}

	_window->redraw();
}
