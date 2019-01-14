#include "planet.h"

Planet::Planet(char color, Window *window) : GameObject(window){
	this->setSize(4,3);
	this->_color = color;
}

void Planet::draw(){
	this->drawBorder();
	_window->addText(_posX+1, _posY+1, "@@", this->_color);
}
