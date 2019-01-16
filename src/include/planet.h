#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"
#include "selectableobject.h"

class Planet : public GameObject, public SelectableObject{
	public:
		Planet(int color, int colorSelected, Window *window);
		void draw();
	private:

};
#endif
