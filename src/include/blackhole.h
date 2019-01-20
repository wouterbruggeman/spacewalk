#ifndef BLACKHOLE_H
#define BLACKHOLE_H

#include "gameobject.h"

class BlackHole : public GameObject{
	public:
		BlackHole(Window *window);
		void draw(int x, int y, bool selected = false);
	private:

};
#endif
