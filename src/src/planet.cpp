#include "planet.h"

void Planet::draw(){
	_window->addText(_posX, _posY, "planet..", false);
}
