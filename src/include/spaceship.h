#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameobject.h"
#include "player.h"

#define MAX_SPACESHIP_SIZE 4

class Player;

class SpaceShip : public GameObject{
	public:
		SpaceShip(unsigned char size, Player *owner, Window *window);
		void draw(bool selected = false);
		void draw(int x, int y, bool selected = false);
		void destroy();
		bool isDestroyed();

		enum Size{
			SIZE_UNSET = 0,
			SMALL = 1,
			MEDIUM = 3,
			LARGE = 4
		};

	private:
		unsigned char _size;
		bool _destroyed;
		Player *_owner;

};
#endif
