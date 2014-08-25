#include "Sprite.h"
#include "SDL.h"
#include "MathUtils.h"
void Sprite::Draw(SDL_Renderer* rend, const Vec2& cameraPos, Vec2 scale, int r, int g, int b, int a)
{
	//maybe we dont need this SDL_RLEACCEL 
	
	destR->x = (pos_.x + cameraPos.x) + (1280 - 1280 * scale.x) / 2;
	destR->y = pos_.y + cameraPos.y;
	destR->w = spriteSize_.x * scale.x;
	destR->h = spriteSize_.y * scale.y;

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
	SDL_SetTextureAlphaMod(pImage_, a);
	SDL_SetTextureColorMod(pImage_, r, g, b); 
	SDL_RenderCopy(rend, pImage_, destL, destR);
}
