#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"
#include "spaceship.h"
#include "strings.h"
#include <vector>

class Planet : public GameObject{
	public:
		Planet(int color, int colorSelected, Window *window);
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		bool addSpaceShip(SpaceShip *s);
		void removeSpaceShip(SpaceShip *s);

		bool containsSpaceShips();
		vector<SpaceShip *> getSpaceShips();

		void selectSpaceShip(int index);
		void moveSelection(bool up);//TODO: Move this function to board

	private:
		bool vectorContainsShipType(SpaceShip *s);
		void sortSpaceShips();
		vector<SpaceShip *> _spaceShips;

		int _selectedSpaceShipIndex;
};
#endif
