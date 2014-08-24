#include "FractureGame.h"

#include <stdlib.h>
#include <ctime>
#include <iostream>
//#include <Box2D/Box2D.h>

void FractureGame::loadAssets()
{

	//new World(); //creates world with levels in order specified above
}

void FractureGame::init()
{
	InitSDL();
	loadAssets();
	Run();
	Clean();


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