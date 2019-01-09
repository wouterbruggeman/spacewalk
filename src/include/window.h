#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <cstring>

#define COLOR_WHITE_BLACK 1
#define COLOR_BLUE_BLACK 2
#define COLOR_GREEN_BLACK 3
#define COLOR_RED_BLACK 4

class Window{
	public:
		Window();
		~Window();
		void start();
		void stop();

		void redraw();
		void clear();

		//Text functions
		void addText(int x, int y, const char *str,
				char color = COLOR_WHITE_BLACK, bool centerHorizontal = false);


		void moveCursor(int x, int y);
		bool isRunning();
		void test();

		int getSizeX();
		int getSizeY();
	private:
		void pairColors();

		bool _isRunning = false;
		int _sizeX;
		int _sizeY;
};
#endif
