#ifndef POPUP_H
#define POPUP_H

#include "gameobject.h"
#include <string.h>

class Popup : public GameObject{
	public:
		Popup(Window *window);
		using GameObject::draw;
		void draw(int x, int y, bool selected = false);

		void setMessage(const char *str);
		char* getString();
	private:
		char _message[100];
};
#endif
