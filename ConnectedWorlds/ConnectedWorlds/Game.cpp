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

Game::Game(void) : running_(true), screenWidth_(DEFAULT_SCREEN_WIDTH), screenHeight_(DEFAULT_SCREEN_HEIGHT)
{
}

Game::~Game()
{
}

void Game::InitSDL()
{

	SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN, &sdlWindow, &sdlRenderer);
	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);

	loadAssets();
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
	SDL_RenderClear(sdlRenderer);
}

void Game::draw()
{

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