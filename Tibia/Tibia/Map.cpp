#include "Map.h"
#include "TextureManager.h"

int lvl1[18][26] = {

	{ 5,5,5,5,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,3,3,3,5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,3,3,3,3,3,3,3,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 5,5,5,5,5,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,4,3,4,3,4,3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,3,4,3,4,3,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,4,3,4,3,4,3,4,3,4,3,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,4,5,4,3,4,3,4,3,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,4,3,4,3,4,3,4,3,4,3,4,3,4,3,0,0,0,0,0,0,0,0,0,0,},
	{ 0,0,0,4,3,4,3,4,3,4,3,4,3,4,3,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,4,3,4,3,4,3,4,3,4,3,4,3,4,3,5,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }

};
Map::Map()
{
	//0
	grass = TextureManager::LoadTexture("../Textures/Floor/grass.png");

	//1
	dirt = TextureManager::LoadTexture("../Textures/Floor/dirt.png");

	//2
	wood = TextureManager::LoadTexture("../Textures/Floor/wood.png");

	//3
	stone = TextureManager::LoadTexture("../Textures/Floor/stone.png");

	//4
	darkStone = TextureManager::LoadTexture("../Textures/Floor/darkstone.png");

	//5
	fireOnStone = TextureManager::LoadTexture("../Textures/Floor/fireOnStone.png");

	LoadMap(lvl1);

	src.x = src.y = 0;
	src.w = 43;
	dest.w = src.w;
	src.h =  43;
	dest.h = src.h;

	dest.x = dest.y = 0;
}

void Map::LoadMap(int arr[18][26])
{
	for (int row = 0; row < 18; row++)
	{
		for (int column = 0; column < 26; column++)
			map[row][column] = arr[row][column];
	}
}

void Map::DrawMap()
{
	int type = 0;
	 
	for (int row = 0; row < 18; row++)
	{
		for (int column = 0; column < 26; column++)
		{
			type = map[row][column];
			dest.x = column * 43;
			dest.y = row * 43;

			switch (type)
			{
			case 0:

				TextureManager::Draw(grass, src, dest);
				break;
			case 1:

				TextureManager::Draw(dirt, src, dest);
				break;
			case 2:

				TextureManager::Draw(wood, src, dest);
				break;
			case 3:

				TextureManager::Draw(stone, src, dest);
				break;
			case 4:

				TextureManager::Draw(darkStone, src, dest);
				break;
			case 5:

				TextureManager::Draw(fireOnStone, src, dest);
				break;

			default:
				break;
			}
		}
	}
}

Map::~Map()
{
}
