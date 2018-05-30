#include "Mob.h"
#include <ctime>



Mob::Mob(const char* textureSheet, int x, int y,int delay):GameObject(textureSheet, x, y,delay)
{
	moveFreely();
}


Mob::~Mob()
{
}
Uint32 timeDelay2(Uint32 interval, void* obj)
{
	GameObject* gameObject = (GameObject*)obj;

	
	gameObject->setOrientation(rand() % 4);


	gameObject->move(gameObject->getOrientation());

	return interval;
}
void Mob::moveFreely()
{
	srand(time(NULL));

	SDL_AddTimer(8*Delay,timeDelay2 , this);


}

void Mob::rotate()
{
	switch (orientation)
	{
	case 0:
		objTexture = TextureManager::LoadTexture("../Textures/Minotaur/right.png");
		break;

	case 1:
		objTexture = TextureManager::LoadTexture("../Textures/Minotaur/up.png");
		break;

	case 2:
		objTexture = TextureManager::LoadTexture("../Textures/Minotaur/left.png");
		break;

	case 3:
		objTexture = TextureManager::LoadTexture("../Textures/Minotaur/front.png");
		break;

	}
}
