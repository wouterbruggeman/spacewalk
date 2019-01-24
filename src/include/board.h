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
		void setStatusMessage(string message);

		void initBodies();
		void resetSelection();
		void moveSelection(int direction);
		bool placeSpaceShip(int index);

		//Movement phase
		bool grabSpaceShips();
		void moveGrabbedShips();


		enum MoveDirection{
			LEFT = 0,
			RIGHT = 1,
			UP = 2,
			DOWN = 3,

		};

	private:

		//Variables
		string _statusMessage;

		int _selectedBody;
		int _selectedSpaceShipIndex;
		GameObject *_bodies[AMOUNT_OF_BODIES];
		vector<SpaceShip *> _grabbedSpaceShips;

		//Pointer to gamedata
		GameData *_gameData;


};
#endif
