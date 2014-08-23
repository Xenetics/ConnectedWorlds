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

	b2Vec2 pos_;
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Texture* image, b2Vec2 pos) : pImage_(image), pos_(pos)
	{
		
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

