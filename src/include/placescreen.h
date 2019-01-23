#ifndef PLACESCREEN_H
#define PLACESCREEN_H

#include "screen.h"
#include "shipview.h"
#include "playerview.h"

#include "movescreen.h"
#include "strings.h"

class PlaceScreen : public Screen{
	public:
		PlaceScreen(GameData *gameData, Window *window);
		~PlaceScreen();
		void draw();
		void handleInput();

	private:
		//Functions
		void placeSpaceShipOnBoard();
		bool playersHaveUnplacedShips();
		void nextScreen();
		void nextPlayer();

		//Variables
		ShipView *_shipView;
};
#endif
