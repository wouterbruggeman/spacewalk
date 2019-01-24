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
		bool bodyIsPlanet(int index);
		int calculateBodyIndex(int index);

		//Place screen functions
		bool placeSpaceShip(int index);

		//Movement screen functions
		bool playerMustSelectSpaceShip();
		void initSpaceShipSelection();

		bool selectPlanet();
		bool hasUnmovedSpaceShips();
		int getAmountOfSameSizedSpaceShips();
		void moveSpaceShipsFromSelectedPlanet();
		void moveSelectedSpaceShip();
		void moveSpaceShip(int index);

		enum MoveDirection{
			LEFT = 0,
			RIGHT = 1,
			UP = 2,
			DOWN = 3,

		};

	private:

		//Variables
		string _statusMessage;

		int _selectedBodyIndex;
		int _selectedSpaceShipIndex;
		int _movedShips;

		GameObject *_bodies[AMOUNT_OF_BODIES];
		//vector<SpaceShip *> _grabbedSpaceShips;

		//Pointer to gamedata
		GameData *_gameData;


};
#endif
