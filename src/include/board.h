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

		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void initBodies();
		void moveSelection(bool right);

	private:

		//Variables
		int _selectedBody;
		GameObject *_bodies[AMOUNT_OF_BODIES];

};
#endif
