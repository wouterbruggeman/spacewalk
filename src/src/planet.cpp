#include "planet.h"

Planet::Planet(int color, int colorSelected, Window *window) :
	GameObject(window, color, colorSelected)
{
	this->setSize(4,3);
	_selectedSpaceShipIndex = -1;
}

void Planet::drawAtPos(int x, int y, bool selected){
	//Draw border and content
	this->drawBorder(x,y);
	_window->addText(x+1, y+1, PLANET_CONTENT, getColor(selected));

	//Draw spaceships on top of the planet
	for(int i = 0; i < _spaceShips.size(); i++){
		//Draw the ship selected if the index equals i
		_spaceShips[i]->drawAtPos(x, (y - i) -1, (i == _selectedSpaceShipIndex));
	}
}

bool Planet::addSpaceShip(SpaceShip *s){
	//TODO: only check the line below in the movement phase
	if(vectorContainsShipType(s)){
		return false;
	}
	_spaceShips.push_back(s);
	return true;
}

bool Planet::containsSpaceShips(){
	return (_spaceShips.size() > 0);
}

bool Planet::containsSpaceShipsOfPlayer(Player *p){
	for(int i = 0; i < _spaceShips.size(); i++){
		if(_spaceShips[i]->getOwner() == p){
			//Return true if the player has spaceships on this planet.
			return true;
		}
	}
	return false;
}

vector<SpaceShip *> Planet::getSpaceShips(){
	return _spaceShips;
}

//returns true if vector already contains ship with size and owner, otherwise false
bool Planet::vectorContainsShipType(SpaceShip *s){
	for(int i = 0; i < _spaceShips.size(); i++){
		if(_spaceShips[i]->sizeEquals(s) && _spaceShips[i]->ownerEquals(s)){
			return true;
		}
	}
	return false;
}

void Planet::selectSpaceShip(int index){
	_selectedSpaceShipIndex = index;
}
