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
		void initBodies();

		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void moveSelection(bool right);
		void resetSelection();

	private:
		//Functions
		int getSelectedPlanetIndex();

		//Variables
		GameObject *_bodies[AMOUNT_OF_BODIES];

};
#endif
