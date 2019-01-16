#include "blackhole.h"

BlackHole::BlackHole(Window *window) : AstronomicalBody(window){
	this->setSize(4,3);
}

void BlackHole::draw(){
	this->drawBorder();
	_window->addText(_posX+1, _posY+1, "  ", COLOR_WHITE_BLACK);
}
