#ifndef PLANET_H
#define PLANET_H

#include "gameobject.h"

class Planet : public GameObject{
	public:
		using GameObject::GameObject;
		void draw();

	private:

};
#endif
