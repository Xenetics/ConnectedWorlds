#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "MathUtils.h"
#include <Box2D/Box2D.h>
#include <Box2D/Common/B2Math.h>
#include <string>

class Sprite
{
protected:
	SDL_Texture* pImage_;

	SDL_Rect* destR;
	SDL_Rect* destL;

	Vec2 pos_; // position in world
	Vec2 ssPos_; // possition of sprite sheet
	Vec2 spriteSize_; // size of prite 
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Texture* image, Vec2 pos, Vec2 spriteSize, Vec2 ssPos = Vec2(0.0f, 0.0f)) : pImage_(image), pos_(pos), ssPos_(ssPos), spriteSize_(spriteSize)
	{
		destR = new SDL_Rect();
		destL = new SDL_Rect();
	}
	virtual void Draw(SDL_Renderer* rend, const Vec2& cameraPosz, float scale);

	virtual ~Sprite()
	{
		if (pImage_)
		{
			// need-----------------------------------
		}
	}

	//accessors
	Vec2 getPos()
	{
		return pos_;
	}
	void setPos(Vec2 pos)
	{
		pos_ = pos;
	}

	void setAlpha(Uint8 alpha)
	{
		alpha = alpha;
	}
};

