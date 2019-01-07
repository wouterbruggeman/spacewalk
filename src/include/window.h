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


		//Text functions
		void addText(int x, int y, const char *str,
				int foregroundColor, int backgroundColor,
				bool centerHorizontal = false);
		void addText(int x, int y, const char *str, bool centerHorizontal = false);


		void moveCursor(int x, int y);
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
