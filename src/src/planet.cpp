#include "planet.h"

Planet::Planet(Window *window) : GameObject(window){

}

void Planet::draw(){
	_window->addText(_posX, _posY, "planet..", false);
}
