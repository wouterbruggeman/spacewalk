#ifndef PLACESCREEN_H
#define PLACESCREEN_H

#include "screen.h"
#include "string.h"
#include "board.h"

class PlaceScreen : public Screen{
	public:
		//using Screen::Screen;
		PlaceScreen(Window *window);
		//~PlaceScreen();
		void draw();

	private:
		Board *_board = nullptr;
};
#endif
