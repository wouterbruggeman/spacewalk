#ifndef GAME_H
#define GAME_H

#include "window.h"
#include "welcomescreen.h"
#include "placescreen.h"
#include "mainscreen.h"

class Game{
	public:
		Game();
		~Game();

		void start();
		void stop();
		void loop();
		void draw();
		bool isRunning();
	private:
		//Functions
		void handleKeyboardInput();

		//Variables
		bool _isRunning = true;
		Window *_window;
 		WelcomeScreen *_welcomeScreen = nullptr;
		PlaceScreen *_placeScreen = nullptr;
		MainScreen *_mainScreen = nullptr;


		int _gamePhrase;
};
#endif
