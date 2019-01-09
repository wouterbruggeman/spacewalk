#ifndef POPUP_H
#define POPUP_H

#include "gameobject.h"

class Popup : public GameObject{
	public:
		Popup(Window *window);
		void setMessage(char *str);
		void draw();

	private:
};
#endif
