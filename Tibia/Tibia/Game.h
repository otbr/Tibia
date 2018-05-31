#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int width, int height, bool fullscreen);

	void handleEvents();
	void update();
	void render();
	void clean();
	//void LoadTextures();
	bool running() { return isRunning; }

	static SDL_Renderer* renderer;
	//GameObject* player;

private:
	int cnt=0;
	bool isRunning = false;
	SDL_Window *window;
	//SDL_Renderer *renderer;
};

