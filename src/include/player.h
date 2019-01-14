#ifndef PLAYER_H
#define PLAYER_H

#include <string.h>

#define MAX_SPACESHIP_AMOUNT 9
#define PLAYERNAME_SIZE 25

class Player{
	public:
		Player();
		~Player();

		void setName(const char *name);
		void getName(char *str);

	private:
		char _name[PLAYERNAME_SIZE];

};
#endif
