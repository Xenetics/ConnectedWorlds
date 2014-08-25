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
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;		
		case WATER:
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		case ICE:
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		case FIRE:
			layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		case SPACE:
			layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		case STORM:
			layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		case DESERT:
			layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 0.0f), Vec2(1280.0f, 720.0f), Vec2(0.0f, 0.0f)));
			break;
		default:
			break;
		}
	}
}

void Level::Draw(SDL_Renderer* rend, Vec2 cameraPos)
{
	for (int i = 0; i < layers[6].objects.size(); i++)
	{
		layers[6].objects[i]->Draw(rend, cameraPos);
	}
	for (int i = 0; i < layers[5].objects.size(); i++)
	{
		layers[5].objects[i]->Draw(rend, cameraPos, Vec2(0.92f, 0.80f), 64, 128, 128, 204);
	}
	for (int i = 0; i < layers[4].objects.size(); i++)
	{
		layers[4].objects[i]->Draw(rend, cameraPos, Vec2(0.846f, 0.64f), 0, 128, 255, 163);
	}
	for (int i = 0; i < layers[3].objects.size(); i++)
	{
		layers[3].objects[i]->Draw(rend, cameraPos, Vec2(0.779f, 0.512f), 255, 128, 0, 130);
	}
	for (int i = 0; i < layers[2].objects.size(); i++)
	{
		layers[2].objects[i]->Draw(rend, cameraPos, Vec2(0.716f, 0.4096f), 200, 200, 200, 104);
	}
	for (int i = 0; i < layers[1].objects.size(); i++)
	{
		layers[1].objects[i]->Draw(rend, cameraPos, Vec2(0.659f, 0.32768f), 128, 0, 128, 83);
	}
	for (int i = 0; i < layers[0].objects.size(); i++)
	{
		layers[0].objects[i]->Draw(rend, cameraPos, Vec2(0.606f, 0.262144f), 128, 64, 0, 67);
	}
}

