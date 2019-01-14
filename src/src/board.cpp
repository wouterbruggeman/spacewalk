#include "board.h"

Board::Board(Window *window) : GameObject(window){

}

void Board::draw(){
	this->drawBorder();
	//_window->addText(_posX, _posY, "board..", false);

	/*Player *p1 = new Player("Player 1");

	SpaceShip s = SpaceShip(5, p1, _window);
	s.setLocation(_posX, _posY+1);
	s.draw();

	Planet *planet = new Planet(COLOR_RED_BLACK, _window);
	planet->setLocation(15,15);
	planet->draw();*/
}
