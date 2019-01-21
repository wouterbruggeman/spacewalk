#ifndef GAMEDATA_H
#define GAMEDATA_H

#include "player.h"
#include "playerview.h"
#include "board.h"
#include "screen.h"

class Screen;
class PlayerView;
class Board;

struct GameData{
	Player *p1;
	Player *p2;
	Player *activePlayer;
	PlayerView *playerView;
	Board *board;
	Screen *currentScreen;
};

#endif
