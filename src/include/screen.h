#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#include "gamedata.h"

#include <time.h>
#include <stdlib.h>

#define MARGIN_X 2
#define MARGIN_Y 1

struct GameData;

class Screen{
	public:
		Screen(GameData *gameData, Window *window);
		virtual ~Screen() = 0;

		virtual void draw() = 0;
		virtual void handleInput() = 0;
	protected:
		//Functions
		void drawStars(int probability);
		virtual void nextScreen() = 0;
		void nextPlayer();

		//Variables
		Window *_window;
		GameData *_gameData;
};
#endif
