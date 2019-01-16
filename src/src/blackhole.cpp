#include "blackhole.h"

BlackHole::BlackHole(Window *window) : AstronomicalBody(window){
	this->setSize(4,3);
}

void BlackHole::draw(){
	this->drawBorder();
}
