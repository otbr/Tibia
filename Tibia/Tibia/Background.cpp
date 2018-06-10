#include "Background.h"



Background::Background()
{
	
	backgroundTex = TextureManager::LoadTexture("../Textures/loading/Loading.png");
	//TextureManager::Draw(backgroundTex, srcRecLoad, destRecLoad);

}

void Background::Render()
{
	TextureManager::Draw(backgroundTex, srcRecLoad, destRecLoad);

}
Background::~Background()
{
}
