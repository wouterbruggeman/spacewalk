#include "blackhole.h"

BlackHole::BlackHole(Window *window) : GameObject(window){
	this->setSize(4,3);
}

void BlackHole::drawAtPos(int x, int y, bool selected){
	this->drawBorder(x,y);
}
