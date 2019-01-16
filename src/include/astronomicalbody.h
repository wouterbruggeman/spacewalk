#ifndef ASTRONOMICALBODY_H
#define ASTRONOMICALBODY_H

#include "gameobject.h"
#include "selectableobject.h"

class AstronomicalBody : public GameObject{
	public:
		AstronomicalBody(Window *window);

		virtual ~AstronomicalBody() = 0;
		void draw() = 0;
};
#endif
