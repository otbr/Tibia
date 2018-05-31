#include "GameObject.h"
#include "TextureManager.h"

//int stopper=0;

GameObject::GameObject(int x, int y,int delay)
{
	
	Delay = delay;
	xpos = x;
	ypos = y;

}

void GameObject::Update() 
{

	srcRect.h = 43;
	srcRect.w = 43;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.x = xpos-20+43;
	destRect.y = ypos-26+43;
	destRect.w = srcRect.w*1.5;
	destRect.h = srcRect.h*1.5;
}

void GameObject::Render()
{
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
