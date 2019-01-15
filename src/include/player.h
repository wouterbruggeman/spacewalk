#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include "window.h"
#include "spaceship.h"

#define MAX_SPACESHIP_AMOUNT 9
#define PLAYERNAME_SIZE 25

class SpaceShip;

class Player{
	public:
		Player(Window *window);
		~Player();

		void setName(const char *name);
		void getName(char *str);

	private:
		//Variables
		Window *_window;

		char _name[PLAYERNAME_SIZE];
		SpaceShip *_spaceShips[MAX_SPACESHIP_AMOUNT];


};
#endif
