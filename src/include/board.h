#ifndef BOARD_H
#define BOARD_H

#include "gameobject.h"

class Board : public GameObject{
	public:
		using GameObject::GameObject;
		void draw();

	private:

};
#endif
