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

bool Planet::addSpaceShip(SpaceShip *s, bool placementPhase){
	//If in the placementphase and the vector already contains this type
	if(placementPhase && vectorContainsShipType(s)){
		return false;
	}

	//Start at the largest spaceship
	for(int i = 0; i < _spaceShips.size(); i++){
		//spaceship is bigger than the current spaceship at i
		if(s->getSize() > _spaceShips[i]->getSize()){
			//Insert before current spaceship
			_spaceShips.insert(_spaceShips.begin() + i, s);
			return true;
		}
	}
	//Spaceship was not placed. Push to the last element
	_spaceShips.push_back(s);
	return true;
}

void Planet::removeSpaceShip(int index){
	//Remove the ship
	_spaceShips.erase(_spaceShips.begin() + index);
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

SpaceShip * Planet::getSpaceShip(int index){
	return _spaceShips[index];
}

int Planet::getSpaceShipsCount(){
	return _spaceShips.size();
}

void Planet::selectSpaceShip(int index){
	_selectedSpaceShipIndex = index;
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
