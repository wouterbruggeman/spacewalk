#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"

class Planet : public GameObject{
	public:
		Planet(int color, int colorSelected, Window *window);
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);
	private:

};
#endif
