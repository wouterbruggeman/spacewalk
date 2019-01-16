#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"
#include "planet.h"
#include "blackhole.h"

#define AMOUNT_OF_BODIES 14

class Board : public GameObject{
	public:
		Board(Window *window);
		~Board();
		void draw();

	private:
		AstronomicalBody *_bodies[AMOUNT_OF_BODIES];

};
#endif
