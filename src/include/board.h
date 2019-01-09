#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"
#include "spaceship.h"
#include "planet.h"

class Board : public GameObject{
	public:
		Board(Window *window);
		void draw();

	private:


};
#endif
