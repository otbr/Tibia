#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Character:public GameObject
{
public:
	Character(int x, int y, int delay);
	~Character();

	void loadTextures();
	void startMove(int direct);
	//void move(int direction);

};

