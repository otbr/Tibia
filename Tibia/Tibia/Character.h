#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Character:public GameObject
{
public:
	Character(const char * textureSheet, int x, int y, int delay);
	~Character();

	void rotate();
};

