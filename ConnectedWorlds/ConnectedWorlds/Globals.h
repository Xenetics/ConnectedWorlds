#pragma once
#include "SDL_image.h"
#include "SDL.h"

enum levelNames{ NORMAL = 0, WATER, ICE, FIRE, SPACE, STORM, DESERT, FLIPPED };

const Vec2 GRAVITY(0.0f, 0.2f);

 
#define ZERO 0.000001f

Vec2 RectToRectCollision(const Vec2& r1Pos, float r1W, float r1H, const Vec2 r2Pos, float r2W, float r2H)
{
	Vec2 retVal(0.0f, 0.0f);

	float r1HalfWidth = r1W / 2.0f;
	float r1HalfHeight = r1H / 2.0f;
	float r2HalfWidth = r2W / 2.0f;
	float r2HalfHeight = r2H / 2.0f;

	Vec2 r1Centre = r1Pos;
	Vec2 r2Centre = r2Pos;

	float overlapX = (r1HalfWidth + r2HalfWidth) -abs(r1Centre.x - r2Centre.x);
	float overlapY = (r1HalfHeight + r2HalfHeight) -abs(r1Centre.y - r2Centre.y);

	if (overlapX > ZERO && overlapY > ZERO)
	{
		//correct on x
		if (overlapX < overlapY)
		{
			if (r1Pos.x < r2Pos.x)
			{
				overlapX *= -1.0f;
			}
			retVal.x = overlapX;
			return retVal;
		}
		//correct on Y
		else
		{
			if (r1Pos.y < r2Pos.y)
			{
				overlapY *= -1.0f;
			}
			retVal.y = overlapY;
			return retVal;
		}
	}
	//no collision
	else
	{
		return retVal;
	}
}
