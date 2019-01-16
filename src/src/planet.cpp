#include "planet.h"

Planet::Planet(int color, int colorSelected, Window *window)
	: GameObject(window),
	SelectableObject(color, colorSelected)
{
	this->setSize(4,3);
}

void Planet::draw(){
	this->drawBorder();
	_window->addText(_posX+1, _posY+1, "@@", getColor());
}
