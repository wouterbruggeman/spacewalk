#include "planet.h"

Planet::Planet(int color, int colorSelected, Window *window) :
	GameObject(window, color, colorSelected)
{
	this->setSize(4,3);
}

void Planet::draw(int x, int y, bool selected){
	this->drawBorder(x,y);
	_window->addText(x+1, y+1, "@@", getColor(selected));
}
