#pragma once

#include "World.h"
#include "Object.h"

#include <vector>

class Level // : World
{
public:
	Level(int whichLevel, SDL_Texture* image) : levelIndex(whichLevel), pSpriteSheet_(image)
	{
	}
	virtual ~Level();
	void Draw();
	int currentLayer;

	struct Layer
	{
		std::vector<Object*> objects;
		int elementType;
		bool isActive;
		float layerGravity;
		SDL_Color layerTintCol;
		//or SDL_PixelFormat ??
	};
	Layer layers[7];

private:
	int levelIndex;
	void BuildLayers(int levelIndex);

	void Level01NormalLayer();
	void Level01FireLayer();
	void Level01IceLayer();

	SDL_Texture* pSpriteSheet_;
};

