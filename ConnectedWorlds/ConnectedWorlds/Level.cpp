#include "Level.h"
#include "Globals.h"

Level::~Level()
{
}

void Level::BuildLayers(int levelOrder[])
{
	for (int i = 0; i < sizeof(levelOrder); i++)
	{
		switch (levelOrder[i])
		{
		case NORMAL:
			{
				layers[0].elementType = NORMAL;
				layers[0].isActive = true;
				layers[0].layerGravity = 1;
				//layers[0].layerTintCol = ;
				layers[0].objects.push_back(new Object(pSpriteSheet_, b2Vec2(300.0f, 300.0f), b2Vec2(200.0f, 30.0f), b2Vec2(200.0f, 30.0)));
			}
			break;
		case WATER:
			break;
		case ICE:
			break;
		case FIRE:
			break;
		case SPACE:
			break;
		case STORM:
			break;
		case DESERT:
			break;
		case FLIPPED:

		default:
			break;
		}
	}

}

void Level::BuildLevel01LayerNormal()
{

}



void Level::Draw(SDL_Renderer* rend, b2Vec2 cameraPos)
{
	for (int i = 0; i < sizeof(layers[0].objects); i++)
	{
		layers[0].objects[i]->Draw(rend, cameraPos);
	}
}

