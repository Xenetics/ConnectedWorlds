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
	SDL_SetRenderDrawColor(sdlRenderer, 255, 255, 255, 255);
}

void Game::InitGame()
{
	//pSpriteSheet = IMG_LoadTexture(sdlRenderer, "Untitled.bmp");
	playerSpriteSheet = IMG_LoadTexture(sdlRenderer, "player.png");

	pSpriteSheet = IMG_LoadTexture(sdlRenderer, "tilesheet.png");

	world = new World(pSpriteSheet);
	player = new Player(playerSpriteSheet,Vec2(300.0f, 555.0f),Vec2(60.0f, 100.0f),Vec2(3.0f,0.0f),Vec2(360.0f,200.0f),7,true);
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
	player->Draw(sdlRenderer, cameraPos);

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
	switch (key)
	{
	case SDL_SCANCODE_ESCAPE:
		running_ = false;
		break;
	}
	player->OnKeyDown(key);
}

void Game::OnKeyUp(Uint16 key)
{
	player->OnKeyUp(key);
}

void Game::Clean()
{
	SDL_Quit();
}

void Game::Update(float deltaTime)
{
	player->Update(deltaTime);
}

void Game::updateCamera()
{
	cameraPos = player->getPos();
	cameraPos.x -= DEFAULT_SCREEN_WIDTH / 2.0f;
	//cameraPos.y -= DEFAULT_SCREEN_WIDTH / 2.0f;

	//now keep camera within level bounds
	if (cameraPos.x < -world->getWidth() / 2.0f)
	{
		cameraPos.x = -world->getWidth() / 2.0f;
	}
	else if (cameraPos.x + DEFAULT_SCREEN_WIDTH >(world->getWidth() / 2.0f))
	{
		cameraPos.x = (world->getWidth() / 2.0f) - DEFAULT_SCREEN_WIDTH;
	}
	/*
	if (cameraPos.y < -pCurrLevel_->GetHeight() / 2.0f)
	{
		cameraPos.y = -pCurrLevel_->GetHeight() / 2.0f;
	}
	else if (cameraPos.y + screenHeight_ >(pCurrLevel_->GetHeight() / 2.0f))
	{
		cameraPos.y = (pCurrLevel_->GetHeight() / 2.0f) - screenHeight_;
	}*/
}
/*
void Game::checkPlayerBounds()
{
	if (pMainCharacter_->GetLeft() <
		pCurrLevel_->getPos().x - (pCurrLevel_->GetWidth() / 2.0f))
	{
		pMainCharacter_->setPos(Vec2((pCurrLevel_->getPos().x -
			(pCurrLevel_->GetWidth() / 2.0f)) +
			pMainCharacter_->GetWidth() / 2.0f,
			pMainCharacter_->getPos().y));
	}
	else if (pMainCharacter_->GetRight() >
		pCurrLevel_->getPos().x + (pCurrLevel_->GetWidth() / 2.0f))
	{
		pMainCharacter_->setPos(Vec2((pCurrLevel_->getPos().x +
			(pCurrLevel_->GetWidth() / 2.0f))
			- pMainCharacter_->GetWidth() / 2.0f,
			pMainCharacter_->getPos().y));
	}

	if (pMainCharacter_->GetTop() <
		pCurrLevel_->getPos().y - pCurrLevel_->GetHeight() / 2.0)
	{
		pMainCharacter_->setPos(Vec2(pMainCharacter_->getPos().x,
			pCurrLevel_->getPos().y - pCurrLevel_->GetHeight()
			/ 2.0f + pMainCharacter_->GetHeight() / 2.0f));
	}
	else if (pMainCharacter_->GetBottom() >
		pCurrLevel_->getPos().y +
		pCurrLevel_->GetHeight() / 2.0f)
	{
		pMainCharacter_->setPos(Vec2(pMainCharacter_->getPos().x,
			pCurrLevel_->getPos().y +
			pCurrLevel_->GetHeight() / 2.0f
			- pMainCharacter_->GetHeight() / 2.0f));
	}
}*/