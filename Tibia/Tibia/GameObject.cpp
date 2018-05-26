#include "GameObject.h"
#include "TextureManager.h"


GameObject::GameObject(const char* textureSheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(textureSheet);

	xpos = x;
	ypos = y;

}

void GameObject::Update() 
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

void GameObject::move(int direction)
{
	switch (direction)
	{
	case 0:
		if(orientation!=0)
			orientation = 0;
		this->setX(43);
		break;
	case 1:
		if (orientation != 1)
			orientation = 1;
		this->setY(-43);

		break;
	case 2:
		if (orientation != 2)
			orientation = 2;
		this->setX(-43);

		break;
	case 3:
		if (orientation != 3)
			orientation = 3;
		this->setY(43);

		break;
	}

}
GameObject::~GameObject()
{
}
