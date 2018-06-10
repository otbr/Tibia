#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Character.h"

class Mob:public GameObject
{
public:
	Mob(int x, int y, int maxhp, int delay);
	~Mob();

	void moveFreely();
	//void move(int direction);

	void startMove(int direct);

	void loadTextures();

	//void targetChampion();
};

