#include "gameobject.h"

GameObject::GameObject(Window *window, int color, int colorSelected){
	_window = window;
	this->setLocation(0,0);
	_color = color;
	_colorSelected = colorSelected;
}

GameObject::~GameObject(){}

void GameObject::draw(bool selected){
	this->draw(_posX, _posY, selected);
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

int GameObject::getColor(bool selected){
	if(selected){
		return _colorSelected;
	}
	return _color;
}

void GameObject::drawBorder(int posX, int posY){
	for(int y = posY; y < (posY + this->_sizeY); y++){
		for(int x = posX; x < (posX + this->_sizeX); x++){
			if(
			((x == posX)  || (x == (posX -1 + this->_sizeX)))
			&& ((y == posY) || (y == posY - 1 + this->_sizeY))
			){
				_window->addText(x, y, BORDER_CORNER);
			}else{
				if(
				(x > posX) && (x < posX - 1 + this->_sizeX)
				&& ((y == posY) || (y == posY - 1 + this->_sizeY))
				){
					_window->addText(x, y, BORDER_HORIZONTAL);
				}else if(
				(y > posY) && (y < posY - 1 + this->_sizeY)
				&& ((x == posX) || (x == posX - 1 + this->_sizeX))
				){
					_window->addText(x, y, BORDER_VERTICAL);
				}else{
					_window->addText(x,y, " ");
				}
			}
		}
	}
}
