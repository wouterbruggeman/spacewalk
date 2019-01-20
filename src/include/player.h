#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include "window.h"
#include "spaceship.h"

#define SPACESHIP_AMOUNT 9
#define PLAYERNAME_SIZE 25

class SpaceShip;

class Player : public GameObject{
	public:
		Player(int color, int colorSelected, Window *window);
		~Player();
		void draw(bool selected = false);
		void draw(int x, int y, bool selected = false);

		void setName(const char *name);
		void getName(char *str);
		SpaceShip* getSpaceShip(int index);

	private:
		//Variables
		char _name[PLAYERNAME_SIZE];
		SpaceShip *_spaceShips[SPACESHIP_AMOUNT];
		int selectedSpaceShipIndex;


};
#endif
