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
			for (int i = 0; i < 7; i++)
			{
				layers[i].isActive = false;
			}
			int makeLayers[3] = { NORMAL, ICE, FIRE };
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
		int tintRGB[3];
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

	std::vector<SDL_Rect> GetObjectRects()
	{
		std::vector<SDL_Rect> ret;
		for (int i = 0; i < layers[currentLayer].objects.size(); i++)
		{
			SDL_Rect temp = SDL_Rect(layers[currentLayer].objects[i]->colRect);
			temp.x += layers[currentLayer].objects[i]->getPos().x;
			temp.y += layers[currentLayer].objects[i]->getPos().y;
			ret.push_back(temp);
		}
		return ret;
	}
	void IncrementLayer()
	{
		currentLayer++;
		if (currentLayer > ActiveLayers() - 1)
		{
			currentLayer = 0;
		}
		SDL_Log("%d", currentLayer);
	}

	int ActiveLayers()
	{
		int ret = 0;
		for (int i = 0; i < 7; i++)
		{
			if (layers[i].isActive)
			{
				ret++;
			}
		}
		return ret;
	}

private:
	int levelIndex;
	void BuildLayers(int levelOrder[]);
	SDL_Texture* pSpriteSheet_;
};

