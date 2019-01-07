#ifndef SHIPSELECTOR_H
#define SHIPSELECTOR_H

#include "gameobject.h"
#include "player.h"

class ShipSelector : public GameObject{
	public:
		ShipSelector(Player *player, Window *window);
		void draw();

	private:
		Player *_player;

};
#endif
