#include <vector>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Character.h"
#include "Mob.h"
#include "Spear.h"

int beginCounter = 0;
bool sPressed = 0;
std::vector<Mob*> enemies;
Mob* enemy1;
Mob* enemy2;
Mob* enemy3;
Mob* enemy4;

Map* map;
Character* player;
SDL_Renderer* Game::renderer = nullptr;


Game::Game()
{

}


Game::~Game()
{
}

void Game::init(const char * title, int width, int height, bool fullscreen)
{

	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Subsystems Initialized" << std::endl;

		window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);

		renderer = SDL_CreateRenderer(window, -1, 0);



		if (renderer)
		{
			

			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			loadingTex = TextureManager::LoadTexture("../Textures/loading/Loading.png");

			
		}

		isRunning = true;

	}


	 /*
	map = new Map();


	enemy1 = new Mob((43-20) +18*43, (43 - 26),22, 60);
	enemy2 = new Mob((43 - 20) + 8*43,(43 - 26) +33*43 , 22, 60);

	enemy3 = new Mob((43 - 20) + 11*43, (43 - 26)+ 14*43, 22, 60);
	enemy4 = new Mob((43 - 20) +22*43, (43 - 26 )+8*43, 22, 60);



	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);


	player = new Character(43 - 20 + 43*5, 43 - 26 + 43 * 4,22, 30);


	player->loadTextures();

	for (auto &p : enemies)
		p->loadTextures();

	viewingPort.h = 800;
	viewingPort.w = 1150;
	viewingPort.x = 200;
	viewingPort.y = 75;

	SDL_RenderSetViewport(Game::renderer, &viewingPort);

	Camera.h = 774;
	Camera.w = 1114;
	Camera.x = 0;
	Camera.y = 0;*/

}

void Game::initRest()
{
	map = new Map();


	enemy1 = new Mob((43 - 20) + 18 * 43, (43 - 26), 22, 60);
	enemy2 = new Mob((43 - 20) + 8 * 43, (43 - 26) + 33 * 43, 22, 60);

	enemy3 = new Mob((43 - 20) + 11 * 43, (43 - 26) + 14 * 43, 22, 60);
	enemy4 = new Mob((43 - 20) + 22 * 43, (43 - 26) + 8 * 43, 22, 60);



	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);


	player = new Character(43 - 20 + 43 * 5, 43 - 26 + 43 * 4, 22, 30);


	player->loadTextures();

	for (auto &p : enemies)
		p->loadTextures();

	viewingPort.h = 800;
	viewingPort.w = 1150;
	viewingPort.x = 200;
	viewingPort.y = 75;

	SDL_RenderSetViewport(Game::renderer, &viewingPort);

	Camera.h = 774;
	Camera.w = 1114;
	Camera.x = 0;
	Camera.y = 0;


}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);


	switch (event.type) {
		case SDL_QUIT:
			isRunning = false;
			break;

		case SDL_KEYDOWN:

			switch (event.key.keysym.sym)
			{
			case SDLK_UP:
				player->startMove(1);
				break;

			case SDLK_DOWN:
				player->startMove(3);

				break;

			case SDLK_LEFT:
				player->startMove(2);

				break;

			case SDLK_RIGHT:
				player->startMove(0);

				break;
			case SDLK_SPACE:
				player->shot(this);
				//std::cout << "ACTUAL X: " << player->getXpos() << std::endl;
				//std::cout << "ACTUAL Y: " << player->getYpos() << std::endl;

				break;
			case SDLK_s:
				sPressed = true;
				break;
			case SDLK_ESCAPE:
				isRunning = false;
				break;
	
			default:
				break;
			}
			break;
		default:
			break;
	}
}
void Game::update()
{
	if (sPressed) {
		player->Update(this);
		for (auto &p : enemies)
			p->Update(this);
		//Center the camera over the dot
		Camera.x = (player->getXpos() + 21) - 1118 / 2;
		Camera.y = (player->getYpos() + 21) - 774 / 2;

		//Keep the camera in bounds
		if (Camera.x < 0)
		{
			Camera.x = 0;
			player->setIsCentered(0);
		}
		if (Camera.y < 0)
		{
			Camera.y = 0;
			player->setIsCentered(0);

		}
		if (Camera.x > 43 * 59 - Camera.w)
		{
			Camera.x = 43 * 59 - Camera.w;
			player->setIsCentered(0);

		}
		if (Camera.y > 43 * 39 - Camera.h)
		{
			player->setIsCentered(0);

			Camera.y = 43 * 39 - Camera.h;
		}
		//setNewVievingPortPosition(player->getXpos(), player->getYpos());

		//SDL_RenderSetViewport(Game::renderer, &viewingPort);
	}

}

void Game::render()
{
	/*if (!beginCounter) {
		SDL_Texture* loadingTex = TextureManager::LoadTexture("../Texutres/loading/Loading.png");
		SDL_Rect srcRectLoading = { 0, 0, 1920, 1080 };
		SDL_Rect destRectLoad = { 0, 0, 1920, 1080 };
		TextureManager::Draw(loadingTex, srcRectLoading, destRectLoad);
		SDL_Delay(3000);
		beginCounter++;
	}*/


	SDL_SetRenderDrawColor(Game::renderer, 0x00, 0x00, 0x00, 0xFF);

	SDL_RenderClear(renderer);

	if (!sPressed) {

		SDL_RenderSetViewport(Game::renderer, nullptr);
		SDL_Rect srcRectLoading = { 0, 0, 1920, 1080 };
		SDL_Rect destRectLoad = { 0, 0, 1920, 1080 };
		TextureManager::Draw(loadingTex, srcRectLoading, destRectLoad);
	}
	if (sPressed) {
		map->DrawMap(this);
		//this is where we would add stuff to render

		player->Render();
		for (auto &p : enemies)
			p->Render();

		if (player->spearsCount())
			player->renderSpears();
	}
		SDL_RenderPresent(renderer);
	
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	SDL_Quit();
	std::cout << "Game Cleaned!" << std::endl;
}

void Game::setXCam(int x)
{
	Camera.x = x;
}

void Game::setYCam(int y)
{
	Camera.y = y;

}

int Game::getXCam()
{
	return Camera.x;
}

int Game::getYCam()
{
	return Camera.y;
}

/*void Game::setNewVievingPortPosition()
{
	viewingPort.x = player->getXpos();
	viewingPort.y = player->getYpos();

	

}*/


