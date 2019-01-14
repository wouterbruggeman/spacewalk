#ifndef PLACESCREEN_H
#define PLACESCREEN_H

#include "screen.h"
#include "strings.h"
#include "board.h"
#include "shipview.h"
#include "playerview.h"

class PlaceScreen : public Screen{
	public:
		//using Screen::Screen;
		PlaceScreen(Board *board, Player *p1, Player *p2, Window *window);
		~PlaceScreen();
		void draw();
		void handleInput();

	private:
		Board *_board;
		ShipView *_shipView;
		PlayerView *_playerView;
		Player *_p1;
		Player *_p2;
};
#endif
