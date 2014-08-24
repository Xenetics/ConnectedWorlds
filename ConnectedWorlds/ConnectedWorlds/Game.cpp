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
	sdlWindow = SDL_CreateWindow("Fractured Worlds", 100, 100, 1280, 720, 0);
	sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_ACCELERATED);
	SDL_SetRenderDrawColor(sdlRenderer, 100, 0, 0, 255);
}

void Game::InitGame()
{
	pSpriteSheet = IMG_LoadTexture(sdlRenderer, "Untitled.bmp");

	world = new World(pSpriteSheet);
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
			HandleEvent(newEvent);
		}

		//get current time to calc delta time with
		QueryPerformanceCounter(&currTime);
		deltaTime = (float)(currTime.QuadPart - prevTime.QuadPart) / (float)frequency.QuadPart;
		prevTime = currTime;

		Update(deltaTime);
		ClearBackBuffer();
		Draw();
	}
}

void Game::ClearBackBuffer()
{
	SDL_RenderClear(sdlRenderer);
}

void Game::Draw()
{
	world->Draw(sdlRenderer, cameraPos);


	SDL_RenderPresent(sdlRenderer);
}

void Game::HandleEvent(const SDL_Event& newEvent)
{
	switch (newEvent.type)
	{
	case SDL_QUIT:
		running_ = false;
		break;
	case SDL_KEYDOWN:
		OnKeyDown(newEvent.key.keysym.scancode);
		break;
	case SDL_KEYUP:
		OnKeyUp(newEvent.key.keysym.scancode);
		break;
	}
}


void Game::OnKeyDown(Uint16 key)
{
	if (key == SDL_SCANCODE_SPACE)
	{
		currentLevel++;
		if (currentLevel > 6)
		{
			currentLevel = 0;
		}
	}
}

void Game::OnKeyUp(Uint16 key)
{

}

void Game::Clean()
{
	SDL_Quit();
}

void Game::Update(float deltaTime)
{

}