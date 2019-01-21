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

void Window::addText(int x, int y, string str,
		char color, bool centerHorizontal){

	attron(COLOR_PAIR(color));

	//Add the text
	int posX = x;
	if(centerHorizontal){
		posX = x - (str.size() / 2);
	}
	mvaddstr(y, posX, str.c_str());

	attroff(COLOR_PAIR(color));
}

string Window::getString(int x, int y, int n){

	int maxChars = n;

	//Show characters
	moveCursor(x,y);

	//Get the string
	string input;
	int movedX = x;

	int ch = getch();
	while(ch != '\n'){
		//Input is between a-Z or 0-9
		if(((ch >= 65) && (ch <= 122)) || ((ch >= 48) && (ch <= 57))){
			//Add new character if allowed by maxChars
			if(input.size() < maxChars){
				input.push_back(ch);
				movedX += 1;
			}

		//Input is backspace character
		}else if(ch == KEY_BACKSPACE){
			//If string has characters to remove
			if(input.size() > 0){
				//Remove last character
				input.pop_back();

				//Update screen
				string character;
				character.push_back(' ');

				movedX -= 1;
				addText(movedX, y, character);
			}

		}
		addText(x,y, input);
		moveCursor(movedX, y);

		ch = getch();
	}

	//Disable the cursor and don't show input anymore
	disableCursor();

	//Return the string
	return input;
}

//For some reason this always leads to a segmentation fault..
/*string Window::getString(int x, int y){
	echo();

	char *str;
	mvgetstr(y,x,str);
	string input = str;

	noecho();
	return input;
}*/

bool Window::isRunning(){
	return _isRunning;
}

int Window::getSizeX(){
	return _sizeX;
}

int Window::getSizeY(){
	return _sizeY;
}

void Window::moveCursor(int x, int y){
	curs_set(1);
	move(y,x);
	refresh();
}

void Window::disableCursor(){
	curs_set(0);
}

void Window::pairColors(){
	//White
	init_pair(COLOR_WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_BLACK_WHITE, COLOR_BLACK, COLOR_WHITE);

	//Red
	init_pair(COLOR_RED_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_BLACK_RED, COLOR_BLACK, COLOR_RED);

	//Green
	init_pair(COLOR_GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
	init_pair(COLOR_BLACK_GREEN, COLOR_BLACK, COLOR_GREEN);

	//Blue
	init_pair(COLOR_BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	init_pair(COLOR_BLACK_BLUE, COLOR_BLACK, COLOR_BLUE);
}
