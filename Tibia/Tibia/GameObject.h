#pragma once
#include "Game.h"

class GameObject
{
public:

	GameObject(const char* textureSheet, int x, int y, int delay);
	~GameObject();

	int getXpos() { return xpos; }
	int getOrientation() { return orientation; }

	bool getIfIsMoving() { return isMoving; };

	void Update();
	void Render();
	void move(int direction);
	void increaseX(int dx) { xpos += dx; }
	void increaseY(int dy) { ypos+=dy; }
	int iloscRuchow() { return ruchy; };
	void zmniejszRuchy() { ruchy--; }
	void changeIsMoving(bool state) { isMoving = state; }
	virtual void rotate()=0;
	void changeTexture(const char* path);

	void setOrientation(int ort) { orientation = ort ; };
protected:
	int xpos;
	int ypos;
	int orientation; //0 RIGHT || 1 UP || 2 LEFT || 3 DOWN 
	int ruchy;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	int Delay;
	bool isMoving = false;
	//SDL_Renderer* renderer;
};

