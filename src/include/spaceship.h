#ifndef SPACESHIP_H
#define SPACESHIP_H

#include "gameobject.h"
#include "selectableobject.h"

#include "player.h"

#define MAX_SPACESHIP_SIZE 4

class Player;

class SpaceShip : public GameObject, public SelectableObject{
	public:
		SpaceShip(unsigned char size, int color, int colorSelected,
			Player *owner, Window *window);
		void draw(bool selected = false);
		void draw(int x, int y, bool selected = false);
		void setState(unsigned char state);
		unsigned char getState();

		enum Size{
			SMALL = 1,
			MEDIUM = 3,
			LARGE = 4
		};

		enum State{
			UNPLACED = 0,
			PLACED = 1,
			DESTROYED = 2
		};

	private:
		unsigned char _size;
		unsigned char _state;
		Player *_owner;

};
#endif
