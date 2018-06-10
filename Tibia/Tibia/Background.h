#pragma once
#include "Game.h"
#include "TextureManager.h"

class Background
{
public:
	Background();
	~Background();
	SDL_Rect srcRecLoad = { 0,0,1920,1080 };
	SDL_Rect destRecLoad = { 0,0,1920,1080 };
	void Render();

private:
	SDL_Texture* backgroundTex;

};

