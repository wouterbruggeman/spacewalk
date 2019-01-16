#include "selectableobject.h"

SelectableObject::SelectableObject(int color, int colorSelected){
	_color = color;
	_colorSelected = colorSelected;
	_selected = false;
}

SelectableObject::~SelectableObject(){}

int SelectableObject::getColor(bool selected){
	if(selected){
		return _colorSelected;
	}
	return _color;
}

bool SelectableObject::getSelected(){
	return _selected;
}
