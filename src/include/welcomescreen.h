#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "screen.h"
#include "popup.h"
#include "placescreen.h"

class WelcomeScreen : public Screen{
	public:
		WelcomeScreen(GameData *gameData, Window *window);
		~WelcomeScreen();
		void draw();
		void handleInput();
		void nextScreen();
	private:
		Popup *_popup;
};
#endif
