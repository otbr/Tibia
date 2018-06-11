#include "GameObject.h"
#include "TextureManager.h"
#include <tuple>

//int stopper=0;

GameObject::GameObject(int x, int y,int maxhp,int delay)
{
	
	maxHP = 22;
	hp = maxhp;
	Delay = delay;
	xpos = x;
	ypos = y;


	//SDL_FillRect(NULL, &backgroundBar, );

	//SDL_SetRenderDrawColor(gRenderer, 0xFF, 0x00, 0x00, 0xFF);
	//SDL_RenderFillRect(Game::renderer, &backgroundBar);
	//SDL_SetRenderDrawColor(Game::renderer, 0xFF, 0x00, 0x00, 0xFF);

	for (int i = 0; i < 4; i++)
		possibleMoves.push_back(1);

}

void GameObject::Update(Game* points) 
{
	

	SDL_SetRenderDrawColor(Game::renderer, 0x2C, 0xD6, 0x0A, 0xFF);
	backgroundBar = { xpos + 15-points->getXCam(), ypos - 2 - points->getYCam(), hp, 3 };
	strokeBar = { xpos + 14 - points->getXCam(), ypos-3 - points->getYCam(), 24, 5 };

	srcRect.h = 43;
	srcRect.w = 43;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos - points->getXCam();
	destRect.y = ypos - points->getYCam();
	destRect.w = srcRect.w*1.5;
	destRect.h = srcRect.h*1.5;

	for (int i = 0; i < 4; ++i)
		possibleMoves[i] = 1;

	//If the object went too far to the left or right
	if (xpos >= 43*57)
		possibleMoves[0]= 0;

	if (ypos <= 36)
		possibleMoves[1] = 0;

	if (xpos <= 39)
		possibleMoves[2] = 0;

	if (ypos >= 43*37)
		possibleMoves[3] = 0;


}


bool GameObject::checkIfTheMoveIsPossible(int direction)
{
	return possibleMoves[direction];
}

void GameObject::Render()
{
	SDL_SetRenderDrawColor(Game::renderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(Game::renderer, &strokeBar);

	SDL_SetRenderDrawColor(Game::renderer, 0x2C, 0xD6, 0x0A, 0xFF);
	SDL_RenderFillRect(Game::renderer, &backgroundBar);
	
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
	
}


void GameObject::updateRotation()
{
	switch (orientation)
	{
	case 0:
		objTexture = objTextures[0];
		break;

	case 1:

		objTexture = objTextures[1];

		break;

	case 2:
		objTexture = objTextures[2];

		break;

	case 3:
		objTexture = objTextures[3];

		break;

	}
}
GameObject::~GameObject()
{
}
