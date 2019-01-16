#include "selectableobject.h"

SelectableObject::SelectableObject(int color, int colorSelected){
	_color = color;
	_colorSelected = colorSelected;
	_selected = false;
}

SelectableObject::~SelectableObject(){}

int SelectableObject::getColor(){
	if(_selected){
		return _colorSelected;
	}
	return _color;
}

void SelectableObject::setSelected(bool state){
	_selected = state;
}

bool SelectableObject::isSelected(){
	return _selected;
}
