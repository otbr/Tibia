#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	//static const int levelWidth = 1920;
	//static const int levelHeight = 1080;

	void init(const char* title, int width, int height, bool fullscreen);
	void initRest();
	void handleEvents();
	void update();
	void render();
	void clean();
	//void LoadTextures();
	bool running() { return isRunning; }
	static SDL_Renderer* renderer;
	//GameObject* player;
	void setXCam(int x);
	void setYCam(int y);
	int getXCam();
	int getYCam();


	
	//void setNewVievingPortPosition();

private:
	SDL_Texture * loadingTex;
	SDL_Texture* loadingpic;
	int cnt=0;
	SDL_Rect Camera;

	bool isRunning = false;
	SDL_Window *window;
	//SDL_Renderer *renderer;
	SDL_Rect viewingPort;
	
};

