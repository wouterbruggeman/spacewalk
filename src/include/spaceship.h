#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameobject.h"
#include "player.h"

class SpaceShip : public GameObject{
	public:
		SpaceShip(int size, Player *owner, Window *window);
		void draw();

	private:
		int _size;
		Player *_owner;

};
#endif
