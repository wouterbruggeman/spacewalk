#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include "window.h"
#include "spaceship.h"
#include "selectableobject.h"

#define SPACESHIP_AMOUNT 9
#define PLAYERNAME_SIZE 25

class SpaceShip;

class Player : public SelectableObject{
	public:
		Player(int color, int colorSelected, Window *window);
		~Player();

		void setName(const char *name);
		void getName(char *str);
		SpaceShip* getSpaceShip(int index);

	private:
		//Variables
		Window *_window;

		char _name[PLAYERNAME_SIZE];
		SpaceShip *_spaceShips[SPACESHIP_AMOUNT];


};
#endif
