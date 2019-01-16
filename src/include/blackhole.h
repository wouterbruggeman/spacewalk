#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "gameobject.h"
#include "selectableobject.h"
#include "astronomicalbody.h"

class BlackHole : public AstronomicalBody{
	public:
		BlackHole(Window *window);
		void draw();
	private:

};
#endif
