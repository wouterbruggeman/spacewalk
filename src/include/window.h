#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <cstring>

class Window{
	public:
		Window();
		~Window();
		void start();
		void stop();

		void redraw();
		void clear();

		void moveCursor(int x, int y);
		void addText(int x, int y, const char *str, bool centerHorizontal = false);
		bool isRunning();
		void test();

		int getSizeX();
		int getSizeY();
	private:

		bool _isRunning = false;
		int _sizeX;
		int _sizeY;
};
#endif
