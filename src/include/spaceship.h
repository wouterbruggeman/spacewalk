#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameobject.h"
#include "player.h"

#define MAX_SPACESHIP_SIZE 4

class Player;

class SpaceShip : public GameObject{
	public:
		SpaceShip(int size, Player *owner, Window *window);
		void draw();

		enum Size{
			SIZE_UNSET = 0,
			SMALL = 1,
			MEDIUM = 3,
			LARGE = 4
		};

	private:
		int _size;
		Player *_owner;

};
#endif
