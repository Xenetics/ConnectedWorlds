#include "Sprite.h"
#include "SDL.h"



void Sprite::Draw(SDL_Renderer* rend, const b2Vec2& cameraPos, float scale)
{
	//maybe we dont need this SDL_RLEACCEL 
	
	destR->x = pos_.x + (1280 - 1280 * scale)/2;
	destR->y = pos_.y;
	destR->w = spriteSize_.x * scale;
	destR->h = spriteSize_.y * scale;

	if (ssPos_ == b2Vec2(0.0f, 0.0f))
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
