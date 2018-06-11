#include "Spear.h"



Spear::Spear(int characterPositionX, int characterPositionY, int directionFromPlayer, Game* points)
{
	spearTexture = TextureManager::LoadTexture("../Textures/Char/spear.png");
	//sXpos = characterPositionX;
	//sYpos = characterPositionY;
	destRect = { characterPositionX - points->getXCam(), characterPositionY - points->getYCam() +25, 47, 6 };
	sRotation = directionFromPlayer;
	angle = 0;

	sVelocityX = 15;
	sVelocityY = 15;


}


Spear::~Spear()
{
	SDL_DestroyTexture(spearTexture);
	sVelocityX = 0;
	sVelocityY = 0;

}

void Spear::update()
{
	
	switch (sRotation)
	{
	case 0:
		destRect.x += sVelocityX ;
		break;
	case 1:
		angle = -90;
		destRect.y -= sVelocityY ;
		break;
	case 2:
		angle = 180;
		destRect.x -= sVelocityX ;
		break;
	case 3:
		angle = -270;
		destRect.y += sVelocityY ;
		break;

	}
	

	sXpos = destRect.x;
	sYpos = destRect.y;

	
}

void Spear::render()
{

	SDL_RenderCopyEx(Game::renderer, spearTexture, &srcRect, &destRect, angle, NULL, SDL_FLIP_NONE);
}



