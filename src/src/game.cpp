#include "game.h"

Game::Game(){
	_window = new Window();

	_board = new Board(_window);
	_p1 = new Player(PLAYER_1_NAME);
	_p2 = new Player(PLAYER_2_NAME);

	_welcomeScreen = new WelcomeScreen(_window);
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

void Game::loop(){
	this->handleKeyboardInput();
	this->draw();
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

void Game::stop(){
	_window->stop();
	_isRunning = false;
}

bool Game::isRunning(){
	return _isRunning;
}

void Game::handleKeyboardInput(){
	char c = getch();

	if((_gamePhrase == 0) && (c == ' ')){
		_gamePhrase++;
	}
}
