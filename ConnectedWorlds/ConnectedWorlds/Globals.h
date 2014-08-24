#pragma once
#include "Box2D/Box2D.h"
#include "SDL_image.h"
#include "SDL.h"

enum levelNames{ NORMAL = 1, WATER, ICE, FIRE, SPACE, STORM, DESERT, FLIPPED };

const b2Vec2 GRAVITY(0.0f, 0.2f);

 /*
#define ZERO 0.000001f

b2Vec2 RectToRectCollision(const b2Vec2& r1Pos, float r1W, float r1H, const b2Vec2 r2Pos, float r2W, float r2H)
{
	b2Vec2 retVal(0.0f, 0.0f);

	float r1HalfWidth = r1W / 2.0f;
	float r1HalfHeight = r1H / 2.0f;
	float r2HalfWidth = r2W / 2.0f;
	float r2HalfHeight = r2H / 2.0f;

	b2Vec2 r1Centre(r1Pos.x + r1W / 2.0f, r1Pos.y + r1H / 2.0f);
	b2Vec2 r2Centre(r2Pos.x + r2W / 2.0f, r2Pos.y + r2H / 2.0f);

	float overlapX = (r1HalfWidth + r2HalfWidth) -
		abs(r1Centre.x - r2Centre.x);
	float overlapY = (r1HalfHeight + r2HalfHeight) -
		abs(r1Centre.y - r2Centre.y);

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
*/