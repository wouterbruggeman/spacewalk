#include "shipview.h"

ShipView::ShipView(Player *p1, Player *p2, Window *window) : GameObject(window){
	this->_p1 = p1;
	this->_p2 = p2;

}

void ShipView::draw(){
	this->drawBorder();
	_window->addText(_posX + 2, _posY + 1, SHIPVIEW_TITLE, COLOR_BLUE_BLACK);
}
