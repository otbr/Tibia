#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Spear
{
public:
	Spear(int characterPositionX, int characterPositionY, int directionFromPlayer, Game* points);
	~Spear();

	void update();
	void render();
	int getX() { return sXpos; }
	int getY() { return sYpos; }

protected:

	int angle;
	int sXpos, sYpos;
	int sVelocityX, sVelocityY;
	int sRotation;

	SDL_Texture* spearTexture;
	
	SDL_Rect srcRect = { 0, 0, 249, 18};
	SDL_Rect destRect;

};

