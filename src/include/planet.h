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

	private:
		bool vectorContainsSize(unsigned char size);
		vector<SpaceShip *> _spaceShips;
};
#endif
