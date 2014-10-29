#pragma once

#include "Sprite.h"
#include "Globals.h"

class Object : public Sprite
{
public:


	Object(SDL_Texture* spriteSheet, Vec2 pos, Vec2 spriteSize, Vec2 ssPos, levelNames type, Vec2 ssSize = Vec2(0.0, 0.0), bool kill = false, bool Solid = true, bool canDestroy = false) : isSolid(Solid), killOnTouch(kill), destroyable(canDestroy), type(type),
		Sprite(spriteSheet, pos, spriteSize, ssPos, ssSize), 
		spriteSheet_(spriteSheet)
	{
		colRect.w = spriteSize.x;
		colRect.h = spriteSize.y;
		colRect.x = 0;
		colRect.y = 0;
	}

	Object(SDL_Texture* spriteSheet, Vec2 pos, Vec2 spriteSize, Vec2 ssPos, SDL_Rect rect, levelNames type, Vec2 ssSize = Vec2(0.0, 0.0), bool kill = false, bool Solid = true, bool canDestroy = false) : colRect(rect), isSolid(Solid),  killOnTouch(kill), destroyable(canDestroy), type(type),
		Sprite(spriteSheet, pos, spriteSize, ssPos, ssSize),
		spriteSheet_(spriteSheet)
	{

	}
	virtual ~Object();

	SDL_Rect GetRect()
	{
		return colRect;
	}

	//private these later
	bool isSolid;
	bool killOnTouch;
	bool isVisable = true;
	bool destroyable;

	levelNames type;
private:
	SDL_Rect colRect;
	SDL_Texture* spriteSheet_;
	
};

