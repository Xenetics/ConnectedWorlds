#include "Game.h"
#include "Collision.h"

#include <iostream>
#include <string>
#include <vector>

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

	pSpriteSheet = IMG_LoadTexture(sdlRenderer, "spriteSheet.png");

	world = new World(pSpriteSheet);
	player = new Player(playerSpriteSheet,Vec2(300.0f, 400.0f),Vec2(60.0f, 100.0f),Vec2(3.0f,12.0f),Vec2(360.0f,200.0f),7,true);

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
	case SDL_SCANCODE_UP:
		//scroll to next dimenion up
		world->GetCurLevel()->IncrementLayer();
		if (player->currentType == NORMAL)
			player->currentType = world->GetCurLevel()->GetCurrentType();
		SDL_Log("Current Type: %d", player->currentType);
		break;
	case SDL_SCANCODE_DOWN:
		world->GetCurLevel()->DecrementLayer();
		if (player->currentType == NORMAL)
			player->currentType = world->GetCurLevel()->GetCurrentType();
		SDL_Log("Current Type: %d", player->currentType);
		//scroll to next dimention down
		break;
	case SDL_SCANCODE_ESCAPE:
		running_ = false;
		break;
	case SDL_SCANCODE_R:
		delete world;
		delete player;
//TODO change this to function that resets all object switches, and player pos, and camera.
		world = new World(pSpriteSheet);
		player = new Player(playerSpriteSheet, Vec2(300.0f, 555.0f), Vec2(60.0f, 100.0f), Vec2(3.0f, 12.0f), Vec2(360.0f, 200.0f), 7, true);
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
	//see if player is dead
	if (player->getPos().y > 1200)
	{
		player->Die();
		CenterCamera();
	}
	DoCollisions();
	updateCamera(deltaTime);
	
}

void Game::updateCamera(float deltaTime)
{
	//now keep camera within level bounds
	if ((player->getPos().x + cameraPos.x) > DEFAULT_SCREEN_WIDTH * 0.8) {
		cameraPos.x -= player->velocity.x * deltaTime;
	}

	if ((player->getPos().x + cameraPos.x) < DEFAULT_SCREEN_WIDTH * 0.2) {
		cameraPos.x -= player->velocity.x * deltaTime;
	}
}

void Game::CenterCamera()
{
	//y too?
	cameraPos.x = (DEFAULT_SCREEN_WIDTH * 0.5) - player->getPos().x;
}


void Game::DoCollisions()
{
	std::vector<SDL_Rect> colRects = world->GetCurLevel()->GetObjectRects();
	//SDL_Log("%f, %f, %f, %f", colRects[0]->x, colRects[0]->y, colRects[0]->w, colRects[0]->h);
	//Vec2 objPos = Vec2(colRects[0]->x, colRects[0]->y);
	Vec2 playerPos  = player->getPos();
	float playerW = player->getSize().x;
	float playerH = player->getSize().y;
	for (int i = 0; i < colRects.size(); i++)
	{
		Vec2 temp;
		Vec2 objPos = Vec2(colRects[i].x + (colRects[i].w * 0.5), colRects[i].y + (colRects[i].h * 0.5));
		Vec2 ret = Collision::RectToRectCollision(playerPos, playerW, playerH, objPos, colRects[i].w, colRects[i].h);
		if (VectorMath::Magnitude(&ret) > VectorMath::Magnitude(&temp))//yes you hit something
		{
			temp = ret;
			//handle collision here
			Object* collision = world->GetCurLevel()->GetActiveObject(i);
			if (collision->isSolid)
			{
				player->setPos(player->getPos() + ret);
				if (ret.y < 0.0f)//you hit the ground
				{
					if (player->onGround == false)
					{
						player->onGround = true;
					}
				}
			}
			if (collision->killOnTouch)
			{
				player->Die();
				CenterCamera();
			}
			if (collision->destroyable)
			{
				if (collision->type == ICE && player->currentType == FIRE)
				{
					collision->isSolid = false;
					collision->isVisable = false;
					player->currentType = NORMAL;
				}
			}
		}	
	}
}