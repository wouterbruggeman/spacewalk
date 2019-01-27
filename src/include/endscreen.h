#ifndef ENDSCREEN_H
#define ENDSCREEN_H

#include "screen.h"
#include "popup.h"

class EndScreen : public Screen{
	public:
		EndScreen(GameData *gameData, Window *window);
		~EndScreen();
		void draw();
		void handleInput();
		void nextScreen();
		int getStatus();

	private:
		//Variables
		Popup *_popup;
		int _status;
};
#endif
