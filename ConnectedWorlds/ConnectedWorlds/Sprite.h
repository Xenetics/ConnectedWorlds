#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <Box2D/Box2D.h>
#include <Box2D/Common/B2Math.h>
#include <string>

class Sprite
{
protected:
	SDL_Texture* pImage_;

	SDL_Rect* destR;
	SDL_Rect* destL;

	b2Vec2 pos_; // position in world
	b2Vec2 ssPos_; // possition of sprite sheet
	b2Vec2 spriteSize_; // size of prite 
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Texture* image, b2Vec2 pos, b2Vec2 spriteSize, b2Vec2 ssPos = b2Vec2(0.0f, 0.0f)) : pImage_(image), pos_(pos), ssPos_(ssPos), spriteSize_(spriteSize)
	{
		destR = new SDL_Rect();
		destL = new SDL_Rect();
	}

	virtual void Draw(SDL_Renderer* rend, const b2Vec2& cameraPosz);

	virtual ~Sprite()
	{
		if (pImage_)
		{
			// need-----------------------------------
		}
	}

	//accessors
	b2Vec2 getPos()
	{
		return pos_;
	}
	void setPos(b2Vec2 pos)
	{
		pos_ = pos;
	}

	void setAlpha(Uint8 alpha)
	{
		alpha = alpha;
	}
};

