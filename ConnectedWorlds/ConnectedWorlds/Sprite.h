#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include "MathUtils.h"
#include <string>

class Sprite
{
protected:
	SDL_Texture* pImage_;

	SDL_Rect* destR;
	SDL_Rect* destL;

	Vec2 pos_; // position in world
	Vec2 ssPos_; // possition of sprite sheet
	Vec2 ssSize_; //asfiuhbiu
	Vec2 spriteSize_; // size of prite 
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Texture* image, Vec2 pos, Vec2 spriteSize, Vec2 ssPos = Vec2(0.0f, 0.0f), Vec2 ssSize = Vec2(0.0f, 0.0f)) : pImage_(image), pos_(pos), ssPos_(ssPos), spriteSize_(spriteSize), ssSize_(ssSize)
	{
		if (ssSize == Vec2(0.0f, 0.0f))
		{
			ssSize_ = spriteSize_;
		}
		destR = new SDL_Rect();
		destL = new SDL_Rect();
	}
	void Draw(SDL_Renderer* rend, const Vec2& cameraPosz, Vec2 scale = Vec2(1.0f, 1.0f), int r = 255, int g = 255, int b = 255, int a = 255);

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

	Vec2 getSize()
	{
		return spriteSize_;
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

