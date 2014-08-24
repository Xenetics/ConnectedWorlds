#pragma once

#include "Sprite.h"

class Object : public Sprite
{
public:
	SDL_Texture* spriteSheet_;

	Object(SDL_Texture* spriteSheet, b2Vec2 pos, b2Vec2 spriteSize, b2Vec2 ssPos) : 
		Sprite(spriteSheet, pos, spriteSize, ssPos), 
		spriteSheet_(spriteSheet)
	{
		
	}
	virtual ~Object();
};

