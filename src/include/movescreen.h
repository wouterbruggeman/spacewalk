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

		enum TurnPhases{
			BEGIN = 0,
			SELECTING = 1,
			MOVING = 2,
			END = 3
		};

	private:
		//Functions

		//TurnPhases
		void handleBeginPhase();
		void handleSelectingPhase();
		void handleMovingPhase();
		void handleEndPhase();

		//Other functions
		bool playerSkipsTurn();
		void nextScreen();
		void nextPlayer();

		//Variables
		Popup *_popup;
		int _turnPhase = 0;

};
#endif
