#include "GameObject.h"
#include "TextureManager.h"

int stopper=0;
GameObject::GameObject(const char* textureSheet, int x, int y,int delay)
{
	objTexture = TextureManager::LoadTexture(textureSheet);
	Delay = delay;
	xpos = x;
	ypos = y;

}

void GameObject::Update() 
{
	rotate();

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

Uint32 process(Uint32 interval, void* obj)
{
	GameObject* gameObject = (GameObject*)obj;
	switch (gameObject->getOrientation()) {
	case 0:
		if (gameObject->iloscRuchow() == 4) {
			gameObject->increaseX(10);
			gameObject->zmniejszRuchy();
			std::cout << "zmiana textury" << std::endl;

		}
		else if (gameObject->iloscRuchow() < 4) {
			gameObject->increaseX(11);
			gameObject->zmniejszRuchy();
			//gameObject->changeTexture("../Textures/Char/front.png");

		}

		if (gameObject->iloscRuchow() > 0)
			return interval;
		break;
	case 1:
		if (gameObject->iloscRuchow() == 4) {
			gameObject->increaseY(-10);
			gameObject->zmniejszRuchy();

		}
		else if (gameObject->iloscRuchow() < 4) {
			gameObject->increaseY(-11);
			gameObject->zmniejszRuchy();

		}

		if (gameObject->iloscRuchow() > 0)
			return interval;
		break;
	case 2:
		if (gameObject->iloscRuchow() == 4) {
			gameObject->increaseX(-10);
			gameObject->zmniejszRuchy();

		}
		else if (gameObject->iloscRuchow() < 4) {
			gameObject->increaseX(-11);
			gameObject->zmniejszRuchy();

		}

		if (gameObject->iloscRuchow() > 0)
			return interval;
		break;
	case 3:
		if (gameObject->iloscRuchow() == 4) {
			gameObject->increaseY(10);
			gameObject->zmniejszRuchy();

		}
		else if (gameObject->iloscRuchow() < 4) {
			gameObject->increaseY(11);
			gameObject->zmniejszRuchy();

		}

		if (gameObject->iloscRuchow() > 0)
			return interval;
		break;
	}
	std::cout << "actual x: " << gameObject->getXpos() << std::endl;
	//gameObject->changeIsMoving();
	//gameObject->changeIsMoving(false);
	return 0;
}

Uint32 timeDelay(Uint32 interval, void* obj)
{
	GameObject* gameObject = (GameObject*)obj;

	if (stopper = 1) {
		gameObject->changeIsMoving(false);
		return 0;
	}

	++stopper;
	return interval;

}
void GameObject::move(int direction)
{
	
	if (isMoving) {
		std::cout << "rusza sie" << std::endl;
		return;
	}

	switch (direction)
	{
	case 0:
		changeIsMoving(true);
		stopper = 0;
		SDL_AddTimer(4*Delay, timeDelay, this);

		if(orientation!=0)
			orientation = 0;

		ruchy = 4;
		SDL_AddTimer(Delay, process, this);

		break;
	case 1:
		changeIsMoving(true);
		stopper = 0;
		SDL_AddTimer(4*Delay, timeDelay, this);
		if (orientation != 1)
			orientation = 1;
		ruchy = 4;
		SDL_AddTimer(Delay, process, this);

		break;
	case 2:
		changeIsMoving(true);
		stopper = 0;
		SDL_AddTimer(4*Delay, timeDelay, this);
		if (orientation != 2)
			orientation = 2;
		ruchy = 4;
		SDL_AddTimer(Delay, process, this);

		break;
	case 3:
		changeIsMoving(true);
		stopper = 0;
		SDL_AddTimer(4*Delay, timeDelay, this);
		if (orientation != 3)
			orientation = 3;
		ruchy = 4;
		SDL_AddTimer(Delay, process, this);

		break;
	}

}
void GameObject::changeTexture(const char * path)
{
	objTexture = TextureManager::LoadTexture(path);
}
GameObject::~GameObject()
{
}
