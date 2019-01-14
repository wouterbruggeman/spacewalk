#include "window.h"

Window::Window(){
	this->start();
}

Window::~Window(){

}

void Window::start(){
	initscr();
	cbreak();

	//Dont show when a user is typing
	noecho();

	//Disable the cursor
	curs_set(0);

	_sizeX = COLS;
	_sizeY = LINES;

	start_color();
	curs_set(0);
	keypad(stdscr, TRUE);

	//Change the status of the current window
	_isRunning = true;

	this->pairColors();
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
	curs_set(1);
}

void Window::addText(int x, int y, const char *str,
		char color, bool centerHorizontal){

	attron(COLOR_PAIR(color));

	//Add the text
	int posX = x;
	if(centerHorizontal){
		posX = x - (strlen(str) / 2);
	}
	mvaddstr(y, posX, str);

	attroff(COLOR_PAIR(color));
}

char* Window::getString(int x, int y){
	echo();
	char *str;
	mvgetstr(y,x,str);
	noecho();
	return str;
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

void Window::pairColors(){
	init_pair(COLOR_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_RED_BLACK, COLOR_RED, COLOR_BLACK);
}
