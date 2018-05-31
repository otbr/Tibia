#pragma once
#include "Game.h"
#include <vector>
class GameObject
{
public:

	GameObject( int x, int y, int delay);
	~GameObject();

	int getXpos() { return xpos; }
	int getOrientation() { return orientation; }
	int getRuchy() { return ruchy; }
	bool getIsFighting() { return isFighting; }
	bool getIfIsMoving() { return isMoving; };


	void Update();
	void Render();
	void increaseX(int dx) { xpos += dx; }
	void increaseY(int dy) { ypos+=dy; }
	int iloscRuchow() { return ruchy; };
	void zmniejszRuchy() { ruchy--; }
	void changeIsMoving(bool state) { isMoving = state; }
	void updateRotation();
	void changeTexture(int index) { objTexture = objTextures[index]; }

	void setOrientation(int ort) { orientation = ort ; };
protected:

	int xpos;
	int ypos;
	int orientation=3; //0 RIGHT || 1 UP || 2 LEFT || 3 DOWN 
	int ruchy;
	std::vector<SDL_Texture*> objTextures;
	SDL_Texture* objTexture;
	SDL_Rect srcRect, destRect;
	int Delay;
	bool isMoving = false;
	bool isFighting = false;
	//SDL_Renderer* renderer;
};

