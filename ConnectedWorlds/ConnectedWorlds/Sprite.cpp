#include "Sprite.h"
#include "SDL.h"
#include "MathUtils.h"



void Sprite::Draw(SDL_Renderer* rend, const Vec2& cameraPos)
{
	//maybe we dont need this SDL_RLEACCEL 
	
	destR->x = pos_.x - spriteSize_.x / 2;
	destR->y = pos_.y - spriteSize_.y / 2;
	destR->w = spriteSize_.x;
	destR->h = spriteSize_.y;

	if (ssPos_ == Vec2(0.0f, 0.0f))
	{
		destL->w = spriteSize_.x;
		destL->h = spriteSize_.y;
		destL->x = ssPos_.x;
		destL->y = ssPos_.y;
	}
	else
	{
		destL->w = spriteSize_.x;
		destL->h = spriteSize_.y;
		destL->x = ssPos_.x;
		destL->y = ssPos_.y;
	}

	SDL_RenderCopy(rend, pImage_, destL, destR);
}
