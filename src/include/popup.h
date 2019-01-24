#ifndef POPUP_H
#define POPUP_H

#include "gameobject.h"
#include "strings.h"
#include <string>

using namespace std;

#define POPUP_SIZE_X 55
#define POPUP_SIZE_Y 8

#define MESSAGE_SIZE_Y 4

class Popup : public GameObject{
	public:
		Popup(Window *window);
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void setMessage(string str, int index = 0);
		void clearMessage();

		string getString(int x = 1, int y = 2, int n = 50);
		bool getBool();

	private:
		string _message[MESSAGE_SIZE_Y];
};
#endif
