#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

#include "gameobject.h"
#include "player.h"
#include "strings.h"
#include "gamedata.h"

#define PLAYERVIEW_SIZE_X 20

struct GameData;

class PlayerView : public GameObject{
	public:
		PlayerView(GameData *gameData, Window *window);
		using GameObject::draw;
		void drawAtPos(int x, int y, bool selected = false);
		void drawMinimal();
	private:
		GameData *_gameData;

};
#endif
