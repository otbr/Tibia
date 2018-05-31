#include "TextureManager.h"

SDL_Texture* TextureManager::LoadTexture(const char* texture)
{
	SDL_Surface* tempSurface = IMG_Load(texture);
	SDL_Texture* tex = SDL_CreateTextureFromSurface(Game::renderer, tempSurface);
	SDL_FreeSurface(tempSurface);

	return tex;
}

void TextureManager::Draw(SDL_Texture * tex, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

void TextureManager::fillTheTextures(std::vector<SDL_Texture*>* theArray, int num)
{
	//std::cout << "boom" << std::endl;
	//for (int i =0; i<4;i++)

		SDL_Texture* temporary;

		switch (num)
		{
		case 0: // character
			temporary = LoadTexture("../Textures/Char/right.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Char/up.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Char/left.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Char/front.png");
			theArray->push_back(temporary);

			break;

		case 1: // minos
			temporary = LoadTexture("../Textures/Minotaur/right.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Minotaur/up.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Minotaur/left.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Minotaur/front.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Minotaur/frontStepLeft.png");
			theArray->push_back(temporary);

			temporary = LoadTexture("../Textures/Minotaur/frontStepRight.png");
			theArray->push_back(temporary);

			break;
		}

		//delete(temporary);

		return;
}
