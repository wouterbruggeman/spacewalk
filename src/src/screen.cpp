#include "screen.h"

Screen::Screen(Window *window){
	_window = window;
}

Screen::~Screen(){

}

void Screen::draw(){

}

bool Screen::isReady(){
	return _isReady;
}

void Screen::handleInput(){

}
