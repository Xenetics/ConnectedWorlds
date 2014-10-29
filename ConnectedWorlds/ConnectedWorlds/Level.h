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
		case 1://level 1
			for (int i = 0; i < 7; i++)
			{
				layers[i].isActive = false;
			}
			int makeLayers[5] = { NORMAL, ICE, FIRE};
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
		levelNames elementType;
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
		std::vector<Layer *> activeLayers;
		int frontLayer = currentLayer;

		for (int i = 0; i < 7; i++)
		{
			if (layers[i].isActive)
			{
				activeLayers.push_back(&layers[i]);
			}
		}
		if (frontLayer < 0)
		{
			frontLayer = activeLayers.size() - 1;
		}

		std::vector<SDL_Rect> ret;
		for (int i = 0; i < activeLayers[frontLayer]->objects.size(); i++)
		{
			SDL_Rect temp = SDL_Rect(activeLayers[frontLayer]->objects[i]->GetRect());
			temp.x += activeLayers[frontLayer]->objects[i]->getPos().x;
			temp.y += activeLayers[frontLayer]->objects[i]->getPos().y;
			ret.push_back(temp);
		}
		return ret;
	}

	levelNames GetCurrentType()
	{
		std::vector<Layer *> activeLayers;
		int frontLayer = currentLayer;

		for (int i = 0; i < 7; i++)
		{
			if (layers[i].isActive)
			{
				activeLayers.push_back(&layers[i]);
			}
		}

		if (frontLayer < 0)
		{
			frontLayer = activeLayers.size() - 1;
		}

		return layers[frontLayer].elementType;
	}

	Object* GetActiveObject(int index)
	{
		std::vector<Layer *> activeLayers;
		int frontLayer = currentLayer;

		for (int i = 0; i < 7; i++)
		{
			if (layers[i].isActive)
			{
				activeLayers.push_back(&layers[i]);
			}
		}

		if (frontLayer < 0)
		{
			frontLayer = activeLayers.size() - 1;
		}
		
		return layers[frontLayer].objects[index];
	}


	void IncrementLayer()
	{
		currentLayer++;
		if (currentLayer > ActiveLayers() - 1)
		{
			currentLayer = 0;
		}
		//SDL_Log("%d", currentLayer);



	}

	void DecrementLayer()
	{
		currentLayer--;
		if (currentLayer < 0)
		{
			currentLayer = ActiveLayers() - 1;
		}
		//SDL_Log("%d", currentLayer);
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

