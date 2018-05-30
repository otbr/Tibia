#include "Character.h"



Character::Character(const char* textureSheet, int x, int y, int delay) :GameObject(textureSheet, x, y,delay)
{
}


Character::~Character()
{
}

void Character::rotate()
{
	switch (orientation)
	{
	case 0:
		objTexture = TextureManager::LoadTexture("../Textures/Char/right.png");
		break;

	case 1:
		objTexture = TextureManager::LoadTexture("../Textures/Char/up.png");
		break;

	case 2:
		objTexture = TextureManager::LoadTexture("../Textures/Char/left.png");
		break;

	case 3:
		objTexture = TextureManager::LoadTexture("../Textures/Char/front.png");
		break;

	}
}
