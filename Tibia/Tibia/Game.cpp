#include <vector>
#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"
#include "Character.h"
#include "Mob.h"

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

void Game::init(const char* title, int width, int height, bool fullscreen)
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
	
	enemy1 = new Mob("../Textures/Minotaur/front.png", 43*8,43*14, 40);
	enemy2 = new Mob("../Textures/Minotaur/front.png",43*15, 43*10, 40);

	enemy3 = new Mob("../Textures/Minotaur/front.png", 43*10, 43*14, 40);
	enemy4 = new Mob("../Textures/Minotaur/front.png", 43*15, 43*7, 40);



	enemies.push_back(enemy1);
	enemies.push_back(enemy2);
	enemies.push_back(enemy3);
	enemies.push_back(enemy4);


	player = new Character("../Textures/Char/front.png", 0 , 0,40);

	map = new Map();
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
				player->move(1);
				break;

			case SDLK_DOWN:
				player->move(3);
				break;

			case SDLK_LEFT:
				player->move(2);
				break;

			case SDLK_RIGHT:
				player->move(0);

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
	player->Update();
	for(auto &p:enemies)
		p->Update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
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