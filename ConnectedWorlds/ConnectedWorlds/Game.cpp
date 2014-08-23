#include "Game.h"
#include <boost/regex.hpp>
#include <iostream>
#include <string>
#include <Box2D/Box2D.h>

#define DEFAULT_SCREEN_WIDTH 1280
#define DEFAULT_SCREEN_HEIGHT 720

#define CLEAR_COLOUR_R 0
#define CLEAR_COLOUR_G 0
#define CLEAR_COLOUR_B 0

Game::Game(void) : running_(true), screenWidth_(DEFAULT_SCREEN_WIDTH), screenHeight_(DEFAULT_SCREEN_HEIGHT), pTestSprite_(0)
{
	//example code for Boost can be and should deleted
	std::string line;
	boost::regex pat("^Subject: (Re: |Aw: )*(.*)");

	while (std::cin)
	{
		std::getline(std::cin, line);
		boost::smatch matches;
		if (boost::regex_match(line, matches, pat))
			std::cout << matches[2] << std::endl;
	}


}

Game::~Game()
{
}

void Game::InitSDL()
{

	SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN, &sdlWindow, &sdlRenderer);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);

	loadAssets();
}

void Game::InitTestImage()
{

	texture = IMG_LoadTexture(sdlRenderer, "untitled.bmp");
	pTestSprite_ = new Sprite(texture, b2Vec2((float)0, (float)0));
}

void Game::Run()
{
	//creat some variable used for determining elapsed time
	LARGE_INTEGER currTime, prevTime, frequency;
	float deltaTime = 0.0f;

	QueryPerformanceFrequency(&frequency);
	QueryPerformanceCounter(&prevTime);

	SDL_Event newEvent;
	while (running_)
	{
		while (SDL_PollEvent(&newEvent))
		{
			handleEvent(newEvent);
		}

		//get current time to calc delta time with
		QueryPerformanceCounter(&currTime);
		deltaTime = (float)(currTime.QuadPart - prevTime.QuadPart) / (float)frequency.QuadPart;
		prevTime = currTime;

		update(deltaTime);
		clearBackBuffer();
		draw();
	}
}

void Game::clearBackBuffer()
{
	
}

void Game::draw()
{
	pTestSprite_->Draw(sdlRenderer, b2Vec2((float)0, (float)0));
}

void Game::handleEvent(const SDL_Event& newEvent)
{
	switch (newEvent.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		onKeyDown(newEvent.key.keysym.scancode);
		break;
	case SDL_KEYUP:
		onKeyUp(newEvent.key.keysym.scancode);
		break;
	}
}


void Game::onKeyDown(Uint16 key)
{

}

void Game::onKeyUp(Uint16 key)
{

}

void Game::Clean()
{
	SDL_Quit();
}