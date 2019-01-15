#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"
#include "planet.h"

class Board : public GameObject{
	public:
		Board(Window *window);
		~Board();
		void draw();

	private:
		//Planet *_planets;

};
#endif
