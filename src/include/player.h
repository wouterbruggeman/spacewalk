#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>

#define MAX_SPACESHIP_AMOUNT 9

class Player{
	public:
		Player();
		~Player();

		void setName(const char *name);
		void getName(char *str);

	private:
		char _name[50];

};
#endif
