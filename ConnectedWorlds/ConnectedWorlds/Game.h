#pragma once
#pragma once

#include <Windows.h>
#include <DirectXMath.h>
#include "SDL.h"
#include "SDL_image.h"
#include "World.h"
#include "SpriteAnimation.h"
#include "Player.h"
#include "MathUtils.h"

class Game
{
private:
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
	SDL_Texture *image;

	void Draw();
	void LoadAssets();
	void Update(float deltaTime);

	bool running_;

	void Game::updateCamera(float deltaTime);
	void Game::checkPlayerBounds();

	Uint16 screenWidth_;
	Uint16 screenHeight_;

	void ClearBackBuffer();
	void HandleEvent(const SDL_Event& newEvent);

	void OnKeyDown(Uint16 key);
	void OnKeyUp(Uint16 key);

	World* world;
	SDL_Texture* pSpriteSheet;
	SDL_Texture* playerSpriteSheet;
	Vec2 cameraPos;

	Player* player;

public:
	Game();
	~Game();

	void InitSDL();
	void Run();
	void Clean();
	void InitGame();
	void DoCollisions();
};

