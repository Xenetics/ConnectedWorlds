#pragma once

#include "SDL.h"
#include "SDL_image.h"

class Sprite
{
protected:
	SDL_Surface* pImage_;

	Uint8 alpha;
public:
	Sprite() : pImage_(0)
	{}
	Sprite(SDL_Surface* image, Uint8 alpha) : pImage_(image), alpha(alpha)
	{}
	virtual ~Sprite()
	{
		if (pImage_)
		{
			SDL_FreeSurface(pImage_);
		}
	}
};

