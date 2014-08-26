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
			layers[0].tintRGB[0] = 255;
			layers[0].tintRGB[1] = 255;
			layers[0].tintRGB[2] = 255;
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;		
		case WATER:
			layers[1].isActive = true;
			layers[1].tintRGB[0] = 64;
			layers[1].tintRGB[1] = 128;
			layers[1].tintRGB[2] = 128;
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		case ICE:
			layers[2].isActive = true;
			layers[2].tintRGB[0] = 0;
			layers[2].tintRGB[1] = 128;
			layers[2].tintRGB[2] = 255;
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		case FIRE:
			layers[3].isActive = true;
			layers[3].tintRGB[0] = 255;
			layers[3].tintRGB[1] = 128;
			layers[3].tintRGB[2] = 0;
			layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		case SPACE:
			layers[4].isActive = true;
			layers[4].tintRGB[0] = 200;
			layers[4].tintRGB[1] = 200;
			layers[4].tintRGB[2] = 200;
			layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		case STORM:
			layers[5].isActive = true;
			layers[5].tintRGB[0] = 128;
			layers[5].tintRGB[1] = 0;
			layers[5].tintRGB[2] = 128;
			layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		case DESERT:
			layers[6].isActive = true;
			layers[6].tintRGB[0] = 128;
			layers[6].tintRGB[1] = 64;
			layers[6].tintRGB[2] = 0;
			layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			break;
		default:
			break;
		}
	}
}

void Level::Draw(SDL_Renderer* rend, Vec2 cameraPos)
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

	frontLayer--;
	if (frontLayer < 0)
	{
		frontLayer = activeLayers.size() - 1;
	}

	SDL_Log("%d", frontLayer);

	SDL_Log("Layer draw order");
	for (int i = activeLayers.size(); i > 0; i--)
	{
		SDL_Log("Layer: %d, Draw Positon: %d", frontLayer, i);
		Layer* temp = activeLayers.at(frontLayer);
		for (int j = 0; j < temp->objects.size(); j++)
		{
			SDL_Log("%f, %f", pow(0.92f, i - 1), pow(0.8f, i - 1));
			temp->objects[j]->Draw(rend, cameraPos, Vec2(pow(0.92f, i - 1), pow(0.8f, i - 1)), temp->tintRGB[0], temp->tintRGB[1], temp->tintRGB[2], 255 - (30 * i));
		}
		frontLayer--;
		if (frontLayer < 0)
		{
			frontLayer = activeLayers.size() - 1;
		}
		
	}
	
	
	/*
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
	*/
}

