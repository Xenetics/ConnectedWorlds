#include "Level.h"
#include "Globals.h"

Level::~Level()
{
}

void Level::BuildLayers(int levelOrder[])
{
	for (int i = 0; i < 7; i++)
	{
		switch (levelOrder[i])
		{
		case NORMAL:
			layers[0].elementType = NORMAL;
			layers[0].isActive = true;
			layers[0].layerGravity = 1;
			//layers[0].layerTintCol = ;
			layers[0].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;		
		case WATER:
			layers[1].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		case ICE:
			layers[2].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		case FIRE:
			layers[3].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		case SPACE:
			layers[4].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		case STORM:
			layers[5].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		case DESERT:
			layers[6].objects.push_back(new Object(pSpriteSheet_, b2Vec2(0.0f, 0.0f), b2Vec2(1280.0f, 720.0f), b2Vec2(0.0f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void Level::Draw(SDL_Renderer* rend, b2Vec2 cameraPos)
{
	for (int i = 0; i < layers[6].objects.size(); i++)
	{
		layers[6].objects[i]->Draw(rend, cameraPos, 0.9f * 0.8f * 0.7f * 0.6f * 0.5f * 0.4f);
	}
	for (int i = 0; i < layers[5].objects.size(); i++)
	{
		layers[5].objects[i]->Draw(rend, cameraPos, 0.9f * 0.8f * 0.7f * 0.6f * 0.5f);
	}
	for (int i = 0; i < layers[4].objects.size(); i++)
	{
		layers[4].objects[i]->Draw(rend, cameraPos, 0.9f * 0.8f * 0.7f * 0.6f);
	}
	for (int i = 0; i < layers[3].objects.size(); i++)
	{
		layers[3].objects[i]->Draw(rend, cameraPos, 0.9f * 0.8f * 0.7f);
	}
	for (int i = 0; i < layers[2].objects.size(); i++)
	{
		layers[2].objects[i]->Draw(rend, cameraPos, 0.9f * 0.8f);
	}
	for (int i = 0; i < layers[1].objects.size(); i++)
	{
		layers[1].objects[i]->Draw(rend, cameraPos, 0.9f);
	}
	for (int i = 0; i < layers[0].objects.size(); i++)
	{
		layers[0].objects[i]->Draw(rend, cameraPos, 1.0f);
	}
}

