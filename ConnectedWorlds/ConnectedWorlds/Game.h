#pragma once
#pragma once

#include <Windows.h>
#include <DirectXMath.h>
#include "SDL.h"
#include "SDL_image.h"
#include "Sprite.h"

class Game
{
protected:
	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;

	SDL_Texture* texture;

	virtual void draw();
	virtual void loadAssets() = 0;
	virtual void update(float deltaTime) = 0;

	bool running_;

	Uint16 screenWidth_;
	Uint16 screenHeight_;

private:
	void clearBackBuffer();
	void handleEvent(const SDL_Event& newEvent);

	virtual void onKeyDown(Uint16 key);
	virtual void onKeyUp(Uint16 key);

	Uint32 clearColour_;

	// For testing purposes
	Sprite* pTestSprite_;
	


public:
	Game(void);
	~Game(void);

	void InitSDL();
	void InitTestImage();
	void Run();
	void Clean();
};

