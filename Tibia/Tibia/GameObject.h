#pragma once
#include "Game.h"
#include <vector>
class GameObject
{
public:

	GameObject( int x, int y, int maxhp, int delay);
	~GameObject();

	int getXpos() { return xpos; }
	int getYpos() { return ypos; }

	int getOrientation() { return orientation; }
	int getRuchy() { return ruchy; }
	bool getIsFighting() { return isFighting; }
	bool getIfIsMoving() { return isMoving; };
	//auto checkBorders();

	void Update(Game* points);
	void Render();
	void increaseX(int dx) { xpos += dx; }
	void increaseY(int dy) { ypos+=dy; }
	int iloscRuchow() { return ruchy; };
	void zmniejszRuchy() { ruchy--; }
	void changeIsMoving(bool state) { isMoving = state; }
	void updateRotation();
	void changeTexture(int index) { objTexture = objTextures[index]; }

	bool checkIfTheMoveIsPossible(int direction);

	void setOrientation(int ort) { orientation = ort ; };

protected:

	std::vector<bool> possibleMoves;
	int xpos;
	int ypos;
	int orientation=3; //0 RIGHT || 1 UP || 2 LEFT || 3 DOWN 
	int ruchy;
	std::vector<SDL_Texture*> objTextures;
	SDL_Rect srcRect, destRect;
	SDL_Texture* objTexture;
	int Delay;
	bool isMoving = false;
	bool isFighting = false;
	//SDL_Renderer* renderer;\

	///////////// FIGHT //////////////

	//HP
	int maxHP;
	int hp;

	SDL_Rect backgroundBar;
	SDL_Rect strokeBar;

	//std::pair<SDL_Rect, SDL_Rect> aboveHeadBar();

	

	//////////////////////////////////
};

