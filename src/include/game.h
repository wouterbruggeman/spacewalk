#ifndef GAME_H
#define GAME_H

#include "welcomescreen.h"
#include "gamedata.h"

class Game{
	public:
		Game();
		~Game();

		void start();
		void stop();
		void loop();
		bool isRunning();

	private:
		//Functions
		void handleKeyboardInput();
		void draw();

		//Variables
		bool _isRunning = true;
		Window *_window;

		GameData *_gameData;
};
#endif
