#ifndef SHIPVIEW_H
#define SHIPVIEW_H

#include "gameobject.h"
#include "player.h"
#include "strings.h"

#define SHIPVIEW_SIZE_X 20

class ShipView : public GameObject{
	public:
		ShipView(Player *p1, Player *p2, Window *window);
		void draw();

	private:
		Player *_p1;
		Player *_p2;


};
#endif
