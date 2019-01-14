#ifndef NAME_INPUT_H
#define NAME_INPUT_H

#include "popup.h"
#include "string.h"

class NameInput : public Popup{
	public:
		NameInput(Window *window);
		char* getString();
	private:

};
#endif
