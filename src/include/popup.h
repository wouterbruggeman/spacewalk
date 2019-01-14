#ifndef POPUP_H
#define POPUP_H

#include "gameobject.h"
#include <string.h>

class Popup : public GameObject{
	public:
		Popup(Window *window);
		void setMessage(const char *str);
		void draw();

	private:
		char _message[100];
};
#endif
