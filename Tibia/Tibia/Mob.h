#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Mob:public GameObject
{
public:
	Mob(const char* textureSheet, int x, int y,int delay);
	~Mob();

	void moveFreely();

	void rotate();
};

