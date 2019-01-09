#ifndef PLAYER_H
#define PLAYER_H

#include <cstring>

#define MAX_SPACESHIP_AMOUNT 9

class Player{
	public:
		Player(const char *name);
		~Player();

		void getName(char *str);

	private:
		char *_name;

};
#endif
