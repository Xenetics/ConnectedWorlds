#include "Level.h"
#include "Globals.h"

Level::~Level()
{
}

void Level::BuildLayers(int levelIndex)
{
	switch (levelIndex)
	{
	case 0:
		Level01NormalLayer();
		Level01FireLayer();
		Level01IceLayer();
		break;
	case 1:
		break;
	case 2:
		break;

	default:
		break;
	}
}

void Level::Level01NormalLayer()
{
	layers[0].elementType = NORMAL;
	layers[0].isActive = true;
	layers[0].layerGravity = 1;
	//layers[0].layerTintCol = ;
	layers[0].objects.push_back(new Object(pSpriteSheet_, b2Vec2(300.0f, 300.0f), b2Vec2(200.0f, 30.0f), b2Vec2(200.0f, 30.0)));
}

void Level::Level01FireLayer()
{

}

void Level::Level01IceLayer()
{
	
}




