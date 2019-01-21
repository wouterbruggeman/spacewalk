#include "planet.h"

Planet::Planet(int color, int colorSelected, Window *window) :
	GameObject(window, color, colorSelected)
{
	this->setSize(4,3);
}

void Planet::drawAtPos(int x, int y, bool selected){
	//Draw border and content
	this->drawBorder(x,y);
	_window->addText(x+1, y+1, PLANET_CONTENT, getColor(selected));

	//Draw spaceships on top of the planet
	for(int i = 0; i < _spaceShips.size(); i++){
		_spaceShips[i]->drawAtPos(x, (y - i) -1);
	}
}

bool Planet::addSpaceShip(SpaceShip *s){
	if(vectorContainsShipType(s)){
		return false;
	}
	_spaceShips.push_back(s);
	return true;
}


//returns true if vector already contains ship with size and owner, otherwise false
bool Planet::vectorContainsShipType(SpaceShip *s){
	for(int i = 0; i < _spaceShips.size(); i++){
		if(_spaceShips[i]->getSize() == s->getSize()
			&& _spaceShips[i]->getOwner() == s->getOwner())
		{
			return true;
		}
	}
	return false;
}
