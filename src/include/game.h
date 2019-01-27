#ifndef GAME_H
#define GAME_H

#include "welcomescreen.h"
#include "endscreen.h"
#include "gamedata.h"

class Game{
	public:
		Game();
		~Game();

		void start();
		void stop();
		int loop();

		enum ExitStatus{
			WAIT = -1,
			EXIT = 0,
			RESTART = 1
		};

	private:
		//Functions
		void handleKeyboardInput();
		void draw();

		//Variables
		Window *_window;
		GameData *_gameData;
};
#endif
