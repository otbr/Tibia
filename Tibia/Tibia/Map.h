#pragma once
#include "Game.h"
class Map
{
public:

	Map();
	~Map();

	void LoadMap(int arr[18][26]);
	void DrawMap();

private:

	SDL_Rect src, dest;

	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* wood;
	SDL_Texture* stone;
	SDL_Texture* darkStone;
	SDL_Texture* fireOnStone;

	int map[18][26];
};

