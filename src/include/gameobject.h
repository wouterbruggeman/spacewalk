#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "window.h"

#define BORDER_CORNER "+"
#define BORDER_HORIZONTAL "-"
#define BORDER_VERTICAL "|"

class GameObject{
	public:
		GameObject(Window *window, int color = COLOR_WHITE_BLACK,
			int colorSelected = COLOR_WHITE_BLACK);
		virtual ~GameObject() = 0;

		void setLocation(int x, int y);
		void setSize(int x, int y);
		void draw(bool selected = false);
		virtual void draw(int x, int y, bool selected = false) = 0;

		int getPosX();
		int getPosY();
		int getSizeX();
		int getSizeY();

		int getColor(bool selected = false);
	private:

	protected:
		void drawBorder(int posX, int posY);

		//Variables
		int _posX;
		int _posY;
		int _sizeX;
		int _sizeY;
		int _color;
		int _colorSelected;
		Window *_window;
};
#endif
