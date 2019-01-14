#include "gameobject.h"

GameObject::GameObject(Window *window){
	_window = window;
	this->setLocation(0,0);
}

GameObject::~GameObject(){

}

void GameObject::drawBorder(){
	for(int y = this->_posY; y < (this->_posY + this->_sizeY); y++){
		for(int x = this->_posX; x < (this->_posX + this->_sizeX); x++){
			if(
			((x == this->_posX)  || (x == (this->_posX -1 + this->_sizeX)))
			&& ((y == this->_posY) || (y == this->_posY - 1 + this->_sizeY))
			){
				_window->addText(x, y, BORDER_CORNER);
			}else{
				if(
				(x > this->_posX) && (x < this->_posX - 1 + this->_sizeX)
				&& ((y == this->_posY) || (y == this->_posY - 1 + this->_sizeY))
				){
					_window->addText(x, y, BORDER_HORIZONTAL);
				}else if(
				(y > this->_posY) && (y < this->_posY - 1 + this->_sizeY)
				&& ((x == this->_posX) || (x == this->_posX - 1 + this->_sizeX))
				){
					_window->addText(x, y, BORDER_VERTICAL);
				}else{
					_window->addText(x,y, " ");
				}
			}
		}
	}
}

void GameObject::setLocation(int x, int y){
	_posX = x;
	_posY = y;
}

void GameObject::setSize(int x, int y){
	_sizeX = x;
	_sizeY = y;
}

int GameObject::getPosX(){
	return this->_posX;
}

int GameObject::getPosY(){
	return this->_posY;
}

int GameObject::getSizeX(){
	return this->_sizeX;
}

int GameObject::getSizeY(){
	return this->_sizeY;
}
