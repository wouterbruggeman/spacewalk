#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"
#include "planet.h"
#include "blackhole.h"
#include "gamedata.h"

#define AMOUNT_OF_BODIES 14

struct GameData;

class Board : public GameObject{
	public:
		Board(GameData *gameData, Window *window);
		~Board();

		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void initBodies();
		void moveSelection(bool right);
		void placeSpaceShip(int index);

	private:

		//Variables
		int _placeStatus;

		int _selectedBody;
		GameObject *_bodies[AMOUNT_OF_BODIES];

		GameData *_gameData;

};
#endif
