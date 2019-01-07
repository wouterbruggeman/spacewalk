#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"

class Planet : public GameObject{
	public:
		Planet(Window *window);
		void draw();

	private:

};
#endif
