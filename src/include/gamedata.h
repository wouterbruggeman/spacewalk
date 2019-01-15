#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "player.h"
#include "board.h"
#include "screen.h"

class Screen;

struct GameData{
	Player *activePlayer;
	Player *p1;
	Player *p2;
	Board *board;
	Screen *currentScreen;
};

#endif
