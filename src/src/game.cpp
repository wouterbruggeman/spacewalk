#include "game.h"

Game::Game(){
	_window = new Window();
	_window->start();
}

Game::~Game(){
	delete _window;
}

void Game::start(){
	WelcomeScreen welcomeScreen = WelcomeScreen(_window);
	welcomeScreen.draw();
}

void Game::loop(){
	this->handleKeyboardInput();
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

}
