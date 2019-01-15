#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#include "gamedata.h"

#define MARGIN_X 2
#define MARGIN_Y 1

struct GameData;

class Screen{
	public:
		Screen(GameData *gameData, Window *window);
		virtual ~Screen();

		virtual void draw();
		virtual void nextScreen();
		virtual void handleInput();
	protected:
		Window *_window;
		GameData *_gameData;
};
#endif
