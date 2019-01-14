#ifndef GAME_H
#define GAME_H

#include "window.h"
#include "welcomescreen.h"
#include "placescreen.h"
#include "mainscreen.h"
#include "player.h"

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
		void handleGamePhrases();
		void draw();

		//Variables
		bool _isRunning = true;
		Window *_window;
 		WelcomeScreen *_welcomeScreen = nullptr;
		PlaceScreen *_placeScreen = nullptr;
		MainScreen *_mainScreen = nullptr;

		Board *_board = nullptr;
		Player *_p1 = nullptr;
		Player *_p2 = nullptr;

		int _gamePhrase;
};
#endif
