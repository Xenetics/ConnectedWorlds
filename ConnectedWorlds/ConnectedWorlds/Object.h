#pragma once

#include "Sprite.h"

class Object : public Sprite
{
public:
	SDL_Texture* spriteSheet_;
	bool isTriggered = false;

	Object(SDL_Texture* spriteSheet, Vec2 pos, Vec2 spriteSize, Vec2 ssPos, Vec2 ssSize = Vec2(0.0f, 0.0f)) :
		Sprite(spriteSheet, pos, spriteSize, ssPos, ssSize),
		spriteSheet_(spriteSheet)
	{
		colRect.w = spriteSize.x;
		colRect.h = spriteSize.y;
		colRect.x = 0;
		colRect.y = 0;
	}

	Object(SDL_Texture* spriteSheet, Vec2 pos, Vec2 spriteSize, Vec2 ssPos, SDL_Rect rect) : colRect(rect),
		Sprite(spriteSheet, pos, spriteSize, ssPos),
		spriteSheet_(spriteSheet)
	{

	}
	virtual ~Object();

	SDL_Rect colRect;
};

