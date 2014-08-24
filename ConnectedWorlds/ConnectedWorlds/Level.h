#pragma once

#include "World.h"
#include "Object.h"
#include "Globals.h"
#include <vector>

class Level // : World
{
public:
	Level(int whichLevel) : levelIndex(whichLevel){}
	virtual ~Level();
	void Draw();
	int currentLayer;

	struct Layer
	{
		std::vector<Object> objects;
		int elementType;
		bool isActive;
		float layerGravity;
	};

private:
	int levelIndex;
	void BuildLayers(int levelIndex);

	void Level01NormalLayer();
	void Level01FireLayer();
	void Level01IceLayer();
};

