#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "screen.h"
#include "inputpopup.h"
#include "placescreen.h"

class WelcomeScreen : public Screen{
	public:
		WelcomeScreen(GameData *gameData, Window *window);
		~WelcomeScreen();
		void draw();
		void handleInput();
		void nextScreen();
	private:
		InputPopup *_inputPopup;
};
#endif
