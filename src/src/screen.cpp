#include "screen.h"

Screen::Screen(GameData *gameData, Window *window){
	//Store the pointers
	_gameData = gameData;
	_window = window;

	//Seed the random function
	srand(time(NULL));
}

Screen::~Screen(){

}

void Screen::draw(){

}

void Screen::nextScreen(){

}

void Screen::drawStars(int probability){
	for(int y = 0; y < _window->getSizeY(); y++){
		for(int x = 0; x < _window->getSizeX(); x++){
			if((rand() % probability) == 0){
				_window->addText(x, y, STAR);
			}
		}
	}
}
