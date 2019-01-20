#ifndef SHIPVIEW_H
#define SHIPVIEW_H

#include "gameobject.h"
#include "player.h"
#include "strings.h"
#include "gamedata.h"

#define SHIPVIEW_SIZE_X 20

class ShipView : public GameObject{
	public:
		ShipView(GameData *gameData, Window *window);
		~ShipView();
		using GameObject::draw;
		void draw(int x, int y, bool selected = false);

	private:
		GameData *_gameData;
		int selectedSpaceShipIndex;

};
#endif
