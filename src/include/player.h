#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>
#include "window.h"
#include "spaceship.h"
#include <string>

using namespace std;

#define SPACESHIP_AMOUNT 9
#define PLAYERNAME_SIZE 25

class SpaceShip;

class Player : public GameObject{
	public:
		Player(int color, int colorSelected, Window *window);
		~Player();
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);

		void setName(string name);
		string getName();
		SpaceShip* getSpaceShip(int index);

	private:
		//Variables
		string _name;
		SpaceShip *_spaceShips[SPACESHIP_AMOUNT];
		int selectedSpaceShipIndex;


};
#endif
