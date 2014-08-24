#pragma once
#pragma once

#include <Windows.h>
#include <DirectXMath.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SpriteAnimation.h"

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

	Uint16 screenWidth_;
	Uint16 screenHeight_;

	void ClearBackBuffer();
	void HandleEvent(const SDL_Event& newEvent);

	void OnKeyDown(Uint16 key);
	void OnKeyUp(Uint16 key);

	int colors[7][4];
	int currentLevel;

public:
	Game();
	~Game();

	void InitSDL();
	void Run();
	void Clean();
};

