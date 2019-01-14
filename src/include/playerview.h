#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "gameobject.h"
#include "player.h"
#include "strings.h"

#define PLAYERVIEW_SIZE_X 20

class PlayerView : public GameObject{
	public:
		PlayerView(Player *p1, Player *p2, Window *window);
		void draw();
		void drawMinimal();
		void setActivePlayer(Player *activePlayer);
	private:
		Player *_p1;
		Player *_p2;

		Player *_activePlayer;


};
#endif
