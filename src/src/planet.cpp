#include "planet.h"

Planet::Planet(int color, int colorSelected, Window *window) :
	SelectableObject(color, colorSelected),
	AstronomicalBody(window)
{
	this->setSize(4,3);
}

void Planet::draw(){
	this->drawBorder();
	_window->addText(_posX+1, _posY+1, "@@", getColor());
}
