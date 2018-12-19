#ifndef GAME_H
#define GAME_H

#include "window.h"
#include "welcomescreen.h"

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

		//Variables
		bool _isRunning = true;
		Window *_window;
};
#endif
