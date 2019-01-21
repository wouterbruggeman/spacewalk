#ifndef PLACESCREEN_H
#define PLACESCREEN_H

#include "screen.h"
#include "shipview.h"
#include "playerview.h"

//#include "mainscreen.h"
#include "strings.h"

class PlaceScreen : public Screen{
	public:
		PlaceScreen(GameData *gameData, Window *window);
		~PlaceScreen();
		void draw();
		void handleInput();

	private:
		ShipView *_shipView;
};
#endif
