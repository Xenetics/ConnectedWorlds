#pragma once

#include "Sprite.h"

class Object : public Sprite
{
public:
	SDL_Texture* spriteSheet_;

	Object(SDL_Texture* spriteSheet, Vec2 pos, Vec2 spriteSize, Vec2 ssPos) : 
		Sprite(spriteSheet, pos, spriteSize, ssPos), 
		spriteSheet_(spriteSheet)
	{
		
	}
	virtual ~Object();
};

