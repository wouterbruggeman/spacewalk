#ifndef PLACESCREEN_H
#define PLACESCREEN_H

#include "screen.h"
#include "strings.h"
#include "board.h"
#include "shipview.h"

class PlaceScreen : public Screen{
	public:
		//using Screen::Screen;
		PlaceScreen(Board *board, Player *p1, Player *p2, Window *window);
		~PlaceScreen();
		void draw();

	private:
		Board *_board;
		ShipView *_shipView;
		Player *_p1;
		Player *_p2;
};
#endif
