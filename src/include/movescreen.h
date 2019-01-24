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
			PHASE_BEGIN = 0,
			PHASE_SELECTING_PLANET = 1,
			PHASE_SELECTING_SPACESHIP = 2,
			PHASE_END = 3
		};

	private:
		//Functions
		//TurnPhases
		void handleBeginPhase();
		void handleSelectingPlanetPhase();
		void handleSelectingSpaceShipPhase();
		void handleEndPhase();

		//Other functions
		void checkMoving();

		bool playerSkipsTurn();
		bool playerGetsNewTurn();
		void nextScreen();
		void nextPlayer();

		//Variables
		Popup *_popup;
		int _turnPhase = 0;

};
#endif
