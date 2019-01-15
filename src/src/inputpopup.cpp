#include "inputpopup.h"

InputPopup::InputPopup(Window *window) : Popup(window){

}

char* InputPopup::getString(){
	return _window->getString(
		((_window->getSizeX() / 2) - this->getSizeX() / 2) + 1,
		((_window->getSizeY() / 2) - this->getSizeY() / 2) + 2
	);
}
