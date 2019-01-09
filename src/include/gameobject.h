#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "window.h"

#define BORDER_CORNER "+"
#define BORDER_HORIZONTAL "-"
#define BORDER_VERTICAL "|"

class GameObject{
	public:
		GameObject(Window *window);
		virtual ~GameObject();

		void setLocation(int x, int y);
		void setSize(int x, int y);
		void draw();
	private:

	protected:
		void drawBorder();

		//Variables
		int _posX;
		int _posY;
		int _sizeX;
		int _sizeY;
		Window *_window;
};
#endif
