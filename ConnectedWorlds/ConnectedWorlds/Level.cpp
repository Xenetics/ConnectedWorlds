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
			//layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), NORMAL, Vec2(100.0f, 100.0f)));
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), NORMAL, Vec2(100.0f, 100.0f), false, false));
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), NORMAL, Vec2(100.0f, 100.0f)));
			layers[0].objects.push_back(new Object(pSpriteSheet_, Vec2(1550.0f, 400.0f), Vec2(200.0f, 200.0f), Vec2(1000.0f, 0.0f), NORMAL, Vec2(200.0f, 200.0f)));
			break;		
		case ICE:
			layers[1].elementType = ICE;
			layers[1].isActive = true;
			layers[1].layerGravity = 1;
			//layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), ICE, Vec2(100.0f, 100.0f)));
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), ICE, Vec2(100.0f, 100.0f), false, true, true));
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), ICE, Vec2(100.0f, 100.0f)));
			layers[1].objects.push_back(new Object(pSpriteSheet_, Vec2(1550.0f, 400.0f), Vec2(200.0f, 200.0f), Vec2(1000.0f, 200.0f), ICE, Vec2(200.0f, 200.0f), false, true, true));
			break;
		case FIRE:
			layers[2].elementType = FIRE;
			layers[2].isActive = true;
			layers[2].layerGravity = 1;
			//layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), FIRE, Vec2(100.0f, 100.0f)));
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), FIRE, Vec2(100.0f, 100.0f), true, false));
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), FIRE, Vec2(100.0f, 100.0f)));
			layers[2].objects.push_back(new Object(pSpriteSheet_, Vec2(1550.0f, 400.0f), Vec2(200.0f, 200.0f), Vec2(1000.0f, 200.0f), FIRE, Vec2(200.0f, 200.0f)));
			break;
		case WATER:
			layers[3].elementType = WATER;
			layers[3].isActive = true;
			layers[3].layerGravity = 1;
			//layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), WATER, Vec2(100.0f, 100.0f)));
			layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), WATER, Vec2(100.0f, 100.0f)));
			layers[3].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), WATER, Vec2(100.0f, 100.0f)));
			break;
		case SPACE:
			layers[4].elementType = SPACE;
			layers[4].isActive = true;
			layers[4].layerGravity = 1;
			//layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), SPACE, Vec2(100.0f, 100.0f)));
			layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), SPACE, Vec2(100.0f, 100.0f)));
			layers[4].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), SPACE, Vec2(100.0f, 100.0f)));
			break;
		case STORM:
			layers[5].elementType = STORM;
			layers[5].isActive = true;
			layers[5].layerGravity = 1;
			//layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), STORM, Vec2(100.0f, 100.0f)));
			layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), STORM, Vec2(100.0f, 100.0f)));
			layers[5].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), STORM, Vec2(100.0f, 100.0f)));
			break;
		case DESERT:
			layers[6].elementType = DESERT;
			layers[6].isActive = true;
			layers[6].layerGravity = 1;
			//layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 605.0f), Vec2(1280.0f, 90.0f), Vec2(0.0f, 605.0f)));
			layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(0.0f, 600.0f), Vec2(800.0f, 100.0f), Vec2(0.0f, 0.0f), DESERT, Vec2(100.0f, 100.0f)));
			layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(800.0f, 600.0f), Vec2(500.0f, 100.0f), Vec2(0.0f, 350.0f), DESERT, Vec2(100.0f, 100.0f)));
			layers[6].objects.push_back(new Object(pSpriteSheet_, Vec2(01300.0f, 600.0f), Vec2(3820.0f, 100.0f), Vec2(0.0f, 0.0f), DESERT, Vec2(100.0f, 100.0f)));

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

	//SDL_Log("%d", frontLayer);

	//SDL_Log("Layer draw order");
	for (int i = activeLayers.size(); i > 0; i--)
	{
		float xOffset = (i - 1) * 80;
		//SDL_Log("Layer: %d, Draw Positon: %d", frontLayer, i);
		Layer* temp = activeLayers.at(frontLayer);
		for (int j = 0; j < temp->objects.size(); j++)
		{
			if (temp->objects[j]->isVisable)
			{
				//SDL_Log("%f, %f", pow(0.92f, i - 1), pow(0.8f, i - 1));
				Vec2 vec = temp->objects[j]->getPos();
				vec.x += xOffset;
				temp->objects[j]->setPos(vec);
				int type = temp->objects[j]->type;
				temp->objects[j]->Draw(rend, cameraPos, Vec2(pow(0.92f, i - 1), pow(0.8f, i - 1)), levelColours[type][0], levelColours[type][1], levelColours[type][2], 255 - (30 * i));
				vec.x -= xOffset;
				temp->objects[j]->setPos(vec);
			}
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

