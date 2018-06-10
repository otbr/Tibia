#include <vector>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Character.h"
#include "Mob.h"
#include "Background.h"

std::vector<Mob*> enemies;
Mob* enemy1;
Mob* enemy2;
Mob* enemy3;
Mob* enemy4;

Background* backImg;
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

			
		}

		isRunning = true;
	}



	map = new Map();


	enemy1 = new Mob((43-20) +4*43 , (43 - 26) + 2*43,22, 60);
	enemy2 = new Mob((43 - 20) + 4*43,(43 - 26) +4*43 , 22, 60);

	enemy3 = new Mob((43 - 20) + 4*43, (43 - 26)+ 6*43, 22, 60);
	enemy4 = new Mob((43 - 20) +4*43, (43 - 26 )+8*43, 22, 60);



	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);


	player = new Character(43 - 20, 43 - 26,22, 60);


	player->loadTextures();

	for (auto &p : enemies)
		p->loadTextures();

	viewingPort.h = 800;
	viewingPort.w = 1400;
	viewingPort.x = 200;
	viewingPort.y = 75;

	SDL_RenderSetViewport(Game::renderer, &viewingPort);

	Camera.h = 774;
	Camera.w = 1114;
	Camera.x = 0;
	Camera.y = 0;

	
	//SDL_Delay(5000);
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
			case SDLK_F10:
				std::cout << "ACTUAL X: " << player->getXpos() << std::endl;
				std::cout << "ACTUAL Y: " << player->getYpos() << std::endl;
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
	

	player->Update(this);
	for(auto &p:enemies)
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
	if (Camera.x > 43 * 60 - Camera.w)
	{
		Camera.x = 43 * 60 - Camera.w;
		player->setIsCentered(0);

	}
	if (Camera.y > 43 * 40 - Camera.h)
	{
		player->setIsCentered(0);

		Camera.y = 43 * 40 - Camera.h;
	}
	//setNewVievingPortPosition(player->getXpos(), player->getYpos());

	//SDL_RenderSetViewport(Game::renderer, &viewingPort);


}

void Game::render()
{
	SDL_SetRenderDrawColor(Game::renderer, 0x00, 0x00, 0x00, 0xFF);

	SDL_RenderClear(renderer);

	//backImg->Render();
	map->DrawMap(this);
	//this is where we would add stuff to render
	
	player->Render();
	for (auto &p : enemies)
		p->Render();

	

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


