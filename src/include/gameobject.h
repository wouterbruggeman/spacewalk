#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "window.h"

class GameObject{
	public:
		GameObject(Window *window);
		virtual ~GameObject();

		void setLocation(int x, int y);
		void draw();
	private:

	protected:
		int _posX;
		int _posY;
		Window *_window;
};
#endif
