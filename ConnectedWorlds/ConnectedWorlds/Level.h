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
	void Draw(SDL_Renderer* rend, Vec2 cameraPos);
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

	float GetWidth()
	{
		float length1, length2;
		int temp = layers[currentLayer].objects.size() - 1;
		length1 = layers[currentLayer].objects[temp]->getSize().x * 0.5;

		length2 = layers[currentLayer].objects[temp]->getPos().x;
		return length1 + length2;
	}

	std::vector<SDL_Rect*> GetObjectRects()
	{
		std::vector<SDL_Rect*> ret;
		for (int i = 0; i < layers[currentLayer].objects.size(); i++)
		{
			SDL_Rect temp = SDL_Rect(layers[currentLayer].objects[i]->colRect);
			temp.x += layers[currentLayer].objects[i]->getPos().x;
			temp.y += layers[currentLayer].objects[i]->getPos().y;
			ret.push_back(&temp);
		}
		return ret;
	}

private:
	int levelIndex;
	void BuildLayers(int levelOrder[]);
	SDL_Texture* pSpriteSheet_;
};

