#include "Character.h"

int stopperr = 0;

Character::Character( int x, int y, int delay) :GameObject( x, y,delay)
{
	loadTextures();

	//objTextures = TextureManager::fillTheTextures(objTextures, 0);
	objTexture = objTextures[3];
}


Character::~Character()
{
}

void Character::loadTextures()
{
	TextureManager::fillTheTextures(&objTextures, 0);

}

Uint32 processi(Uint32 interval, void* obj)
{
	Character* charac = (Character*)obj;

	switch (charac->getOrientation()) {
	case 0:
		if (charac->iloscRuchow() == 4) {
			charac->increaseX(10);
			charac->zmniejszRuchy();
			//std::cout << "zmiana textury" << std::endl;

		}
		else if (charac->iloscRuchow() < 4) {
			charac->increaseX(11);
			charac->zmniejszRuchy();
			//gameObject->changeTexture("../Textures/Char/front.png");

		}

		if (charac->iloscRuchow() > 0)
			return interval;
		break;
	case 1:
		if (charac->iloscRuchow() == 4) {
			charac->increaseY(-10);
			charac->zmniejszRuchy();

		}
		else if (charac->iloscRuchow() < 4) {
			charac->increaseY(-11);
			charac->zmniejszRuchy();

		}

		if (charac->iloscRuchow() > 0)
			return interval;
		break;
	case 2:
		if (charac->iloscRuchow() == 4) {
			charac->increaseX(-10);
			charac->zmniejszRuchy();

		}
		else if (charac->iloscRuchow() < 4) {
			charac->increaseX(-11);
			charac->zmniejszRuchy();

		}

		if (charac->iloscRuchow() > 0)
			return interval;
		break;
	case 3:
		if (charac->iloscRuchow() == 4) {
			charac->increaseY(10);
			charac->zmniejszRuchy();

		}
		else if (charac->iloscRuchow() < 4) {
			charac->increaseY(11);
			charac->zmniejszRuchy();

		}

		if (charac->iloscRuchow() > 0)
			return interval;
		break;
	}

	return 0;
}

Uint32 timeDelayy(Uint32 interval, void* obj)
{
	Character* charac = (Character*)obj;

	if (stopperr = 1) {
		charac->changeIsMoving(false);
		return 0;
	}

	++stopperr;
	return interval;

}

void Character::startMove(int direct)
{
	if (isMoving)
		return;

	changeIsMoving(true);

	if (orientation != direct) {
		orientation = direct;
		updateRotation();
	}

	stopperr = 0;
	SDL_AddTimer(4 * Delay, timeDelayy, this);

	ruchy = 4;

	SDL_AddTimer(Delay, processi, this);

}



