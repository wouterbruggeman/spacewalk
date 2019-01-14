#ifndef SCREEN_H
#define SCREEN_H

#include "window.h"
#define MARGIN_X 2
#define MARGIN_Y 1

class Screen{
	public:
		Screen(Window *window);
		virtual ~Screen();

		void draw();
		bool isReady();
	protected:
		Window *_window;
		bool _isReady = false;
};
#endif
