#ifndef WELCOMESCREEN_H
#define WELCOMESCREEN_H

#include "window.h"
#include "screen.h"
#include "player.h"
#include "nameinput.h"
//#include "string.h"

class WelcomeScreen : public Screen{
	public:
		WelcomeScreen(Player *p1, Player *p2, Window *window);
		~WelcomeScreen();
		void draw();
		void handleInput();
	private:
		NameInput *_nameInput;
		Player *_p1;
		Player *_p2;
};
#endif
