#pragma once


#include "Object.h"
#include "Globals.h"

#include <vector>

class Level
{
public:
	Level(){}
	Level(int whichLevel, SDL_Texture* image) : levelIndex(whichLevel), pSpriteSheet_(image)
	{
		switch(levelIndex)
		{
		case 1:
			int makeLayers[7] = { NORMAL, WATER, ICE, FIRE, SPACE, STORM, DESERT };
			BuildLayers(makeLayers);
			break;
		}
	}

	~Level();
	void Draw(SDL_Renderer* rend, b2Vec2 cameraPos);
	int currentLayer = 0;

	struct Layer
	{
		std::vector<Object*> objects;
		int elementType;
		bool isActive;
		float layerGravity;
		SDL_Color layerTintCol;
	};
	Layer layers[7];

private:
	int levelIndex;
	void BuildLayers(int levelOrder[]);
	SDL_Texture* pSpriteSheet_;
};

