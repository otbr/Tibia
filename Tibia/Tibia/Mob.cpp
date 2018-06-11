#include "Mob.h"
#include <ctime>

int stopper = 0;

Mob::Mob(int x, int y, int maxhp, int delay):GameObject( x, y, maxhp, delay)
{
	loadTextures();
	objTexture = objTextures[3];


	moveFreely();
}


Mob::~Mob()
{
}

Uint32 timeDelay2(Uint32 interval, void* obj)
{
	Mob* mobix = (Mob*)obj;

	int yolo = rand() % 4;

	
	mobix->startMove(yolo);

	return interval;
	//SDL_AddTimer(rand() % 4, timeDelay2, nullptr);
	//return 0;
}

void Mob::moveFreely()
{

	SDL_AddTimer(12*Delay*((rand()%4)+1),timeDelay2 , this);


}

Uint32 process(Uint32 interval, void* obj)
{
	Mob* mobix = (Mob*)obj;

	switch (mobix->getOrientation()) {
	case 0:
		if (mobix->iloscRuchow() == 4) {
			mobix->increaseX(10);
			mobix->zmniejszRuchy();
			//std::cout << "zmiana textury" << std::endl;

		}
		else if (mobix->iloscRuchow() < 4) {
			mobix->increaseX(11);
			mobix->zmniejszRuchy();
			//gameObject->changeTexture("../Textures/Char/front.png");

		}

		if (mobix->iloscRuchow() > 0)
			return interval;
		break;
	case 1:
		if (mobix->iloscRuchow() == 4) {
			mobix->increaseY(-10);
			mobix->zmniejszRuchy();

		}
		else if (mobix->iloscRuchow() < 4) {
			mobix->increaseY(-11);
			mobix->zmniejszRuchy();

		}

		if (mobix->iloscRuchow() > 0)
			return interval;
		break;
	case 2:
		if (mobix->iloscRuchow() == 4) {
			mobix->increaseX(-10);
			mobix->zmniejszRuchy();

		}
		else if (mobix->iloscRuchow() < 4) {
			mobix->increaseX(-11);
			mobix->zmniejszRuchy();

		}

		if (mobix->iloscRuchow() > 0)
			return interval;
		break;
	case 3:
		if (mobix->iloscRuchow() == 4) {
			mobix->increaseY(10);
			mobix->zmniejszRuchy();
			mobix->changeTexture(5);
		}
		else if (mobix->iloscRuchow() < 4) {
			mobix->increaseY(11);

			if (mobix->getRuchy() == 3)
			mobix->changeTexture(5);

			else if (mobix->getRuchy() == 2)
				mobix->changeTexture(4);

			else if (mobix->getRuchy() == 1)
				mobix->changeTexture(3);

			mobix->zmniejszRuchy();

		}

		if (mobix->iloscRuchow() > 0)
			return interval;
		break;
	}

	return 0;
}

Uint32 timeDelay(Uint32 interval, void* obj)
{
	Mob* mobix = (Mob*)obj;

	if (stopper = 1) {
		mobix->changeIsMoving(false);
		return 0;
	}

	++stopper;
	return interval;

}

void Mob::startMove(int direct)
{

	if (isMoving)
		return;
	if (!possibleMoves[direct])
		return;

	changeIsMoving(true);
	srand(time(NULL));


	if (orientation != direct) {
		orientation = direct;
		updateRotation();
	}

	stopper = 0;
	SDL_AddTimer(4 * Delay, timeDelay, this);

	ruchy = 4;

	SDL_AddTimer(Delay, process, this);

}

void Mob::loadTextures()
{
	TextureManager::fillTheTextures(&objTextures, 1);

}

