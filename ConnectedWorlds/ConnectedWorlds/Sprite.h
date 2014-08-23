#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <Box2D/Box2D.h>
#include <Box2D/Common/B2Math.h>

class Sprite
{
protected:
	SDL_Surface* pImage_;

	b2Vec2 pos_;
	Uint8 alpha;
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Surface* image, b2Vec2 pos, Uint8 alpha) : pImage_(image), alpha(alpha)
	{}
	virtual void Draw(SDL_Surface* surfaceToDrawOn, const b2Vec2& cameraPosz);

	virtual ~Sprite()
	{
		if (pImage_)
		{
			SDL_FreeSurface(pImage_);
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
	Uint8 getAlpha()
	{
		return alpha;
	}

	void setAlpha(Uint8 alpha)
	{
		alpha = alpha;
	}
};

