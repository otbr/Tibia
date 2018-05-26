#pragma once
#include "Game.h"

class GameObject
{
public:

	GameObject(const char* textureSheet, int x, int y);
	~GameObject();

	void Update();
	void Render();
	void move(int direction);
	void setX(int dx) { xpos += dx; }
	void setY(int dy) { ypos+=dy; }


private:
	int xpos;
	int ypos;
	int orientation; //0 RIGHT || 1 UP || 2 LEFT || 3 DOWN 

	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	//SDL_Renderer* renderer;
};

