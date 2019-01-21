#include "mainscreen.h"

MainScreen::MainScreen(GameData *gameData, Window *window) : Screen(gameData, window){

}

MainScreen::~MainScreen(){

}

void MainScreen::draw(){
	_window->clear();
}

void MainScreen::handleInput(){
	char c = getch();
}
