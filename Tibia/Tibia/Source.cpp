#include "Game.h"
#include <SDL.h>


Game *game = NULL;
int main(int argc, char *args[])
{

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint32 frameStart;
	int frameTime;

	game = new Game();
	game->init("Begginings", 1920,1080, 1);
	game->initRest();

	


	while (game->running()) {

		frameStart = SDL_GetTicks();
		
		game->handleEvents();
		game->update();
		game->render();
		

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}

	game->clean();

	return 0;
}