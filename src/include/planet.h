#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"
#include "selectableobject.h"
#include "astronomicalbody.h"

class Planet : public AstronomicalBody, public SelectableObject{
	public:
		Planet(int color, int colorSelected, Window *window);
		void draw();
	private:

};
#endif
