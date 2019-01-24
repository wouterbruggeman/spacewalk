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

		bool addSpaceShip(SpaceShip *s, bool placementPhase);
		void removeSpaceShip(int index);

		bool containsSpaceShips();
		bool containsSpaceShipsOfPlayer(Player *p);

		vector<SpaceShip *> getSpaceShips();
		SpaceShip *getSpaceShip(int index);
		int getSpaceShipsCount();

		void selectSpaceShip(int index);

	private:
		bool vectorContainsShipType(SpaceShip *s);
		void sortSpaceShips();
		vector<SpaceShip *> _spaceShips;

		int _selectedSpaceShipIndex;
};
#endif
