#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"

class Screen{
	public:
		Screen(Window *window);
		virtual ~Screen();

		void draw();
	protected:
		Window *_window;
};
#endif
