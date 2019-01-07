#include "window.h"

Window::Window(){
	this->start();
}

Window::~Window(){

}

void Window::start(){
	initscr();
	_sizeX = COLS;
	_sizeY = LINES;

	start_color();
	curs_set(0);
	keypad(stdscr, TRUE);

	//Change the status of the current window
	_isRunning = true;
}

/* Stop the current window */
void Window::stop(){
	_isRunning = false;
	endwin();
}

void Window::redraw(){
	refresh();
}

void Window::clear(){
	erase();
}

void Window::moveCursor(int x, int y){

}

void Window::addText(int x, int y, const char *str,
		int foregroundColor, int backgroundColor,
		bool centerHorizontal){

	init_pair(1, foregroundColor, backgroundColor);
	attron(COLOR_PAIR(1));

	//Add the text
	this->addText(x, y, str, centerHorizontal);

	attroff(COLOR_PAIR(1));
}

void Window::addText(int x, int y, const char *str, bool centerHorizontal){
	int posX = x;
	if(centerHorizontal){
		posX = x - (strlen(str) / 2);
	}
	mvaddstr(y, posX, str);

}

bool Window::isRunning(){
	return _isRunning;
}

int Window::getSizeX(){
	return _sizeX;
}

int Window::getSizeY(){
	return _sizeY;
}
