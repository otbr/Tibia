#pragma once
#include "GameObject.h"
#include "TextureManager.h"

class Character:public GameObject
{
public:
	Character(int x, int y,int maxhp, int delay);
	~Character();

	void loadTextures();
	void startMove(int direct);
	//void setCamera(SDL_Rect& camera);
	bool getIsCentered() { return isCentered; }
	void setIsCentered(int value) { isCentered = value; }

	
private:
	bool isCentered=0;

	//void move(int direction);

};

