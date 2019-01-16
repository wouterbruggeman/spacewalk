#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>
#include <cstring>

//White
#define COLOR_WHITE_BLACK 1
#define COLOR_BLACK_WHITE 2

//Red
#define COLOR_RED_BLACK 3
#define COLOR_BLACK_RED 4

//Green
#define COLOR_GREEN_BLACK 5
#define COLOR_BLACK_GREEN 6

//Blue
#define COLOR_BLUE_BLACK 7
#define COLOR_BLACK_BLUE 8

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
		char* getString(int x, int y);

		void moveCursor(int x, int y);
		bool isRunning();

		int getSizeX();
		int getSizeY();
	private:
		void pairColors();

		bool _isRunning = false;
		int _sizeX;
		int _sizeY;
};
#endif
