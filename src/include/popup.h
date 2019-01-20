#ifndef POPUP_H
#define POPUP_H

#include "gameobject.h"
#include <string>

using namespace std;

class Popup : public GameObject{
	public:
		Popup(Window *window);
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void setMessage(string str);
		string getString();
	private:
		string _message;
};
#endif
