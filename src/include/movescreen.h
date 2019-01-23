#ifndef MOVESCREEN_H
#define MOVESCREEN_H

#include "screen.h"
#include "string.h"
#include "popup.h"

class MoveScreen : public Screen{
	public:
		MoveScreen(GameData *gameData, Window *window);
		~MoveScreen();
		void draw();
		void handleInput();
	private:
		//Functions
		bool playerSkipsTurn();
		void nextScreen();
		void nextPlayer();

		//Variables
		Popup *_popup;

};
#endif
