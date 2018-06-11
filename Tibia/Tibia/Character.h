#pragma once
#include "GameObject.h"
#include "TextureManager.h"
#include "Spear.h"

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
	void shot(Game* points);
	void renderSpears();
	int spearsCount() { return spearsCounts; }



	
private:
	int spearsCounts = 0;
	bool isCentered=0;
	SDL_Texture* spearTexture;
	int spearVelocity;
	int xSpear;
	int ySpear;
	int rotationSpear;
	SDL_Rect destSpear;
	SDL_Rect srcRect = {xpos, ypos, 249, 19};

	std::vector<Spear*> spears;
	//void move(int direction);

};

