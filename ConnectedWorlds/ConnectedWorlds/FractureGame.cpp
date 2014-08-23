#include "FractureGame.h"
#include <stdlib.h>
#include <ctime>
#include <iostream>

void FractureGame::loadAssets()
{

}

void FractureGame::update(float deltaTime)
{

}

void FractureGame::onKeyDown(Uint16 key)
{
	switch (key)
	{
	case SDL_SCANCODE_ESCAPE:
		running_ = false;
		break;
	default:
		break;
	}
}

void FractureGame::onKeyUp(Uint16 key)
{
	
}

void FractureGame::draw()
{
	Game::draw();
}

void FractureGame::updateCamera()
{

}