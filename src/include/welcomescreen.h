#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "screen.h"
#include "popup.h"
#include "placescreen.h"
#include "movescreen.h"	//TODO: remove this line

class WelcomeScreen : public Screen{
	public:
		WelcomeScreen(GameData *gameData, Window *window);
		~WelcomeScreen();
		void draw();
		void handleInput();
		void nextScreen();
	private:
		//Variables
		Popup *_popup;
};
#endif
