#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"

class Planet : public GameObject{
	public:
		Planet(char color, Window *window);
		void draw();

	private:
		char _color;
};
#endif
