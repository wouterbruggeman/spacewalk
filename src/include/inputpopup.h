#ifndef INPUTPOPUP_H
#define INPUTPOPUP_H

#include "popup.h"
#include "string.h"

class InputPopup : public Popup{
	public:
		InputPopup(Window *window);
		char* getString();
	private:

};
#endif
