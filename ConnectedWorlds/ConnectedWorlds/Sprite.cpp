#include "Sprite.h"
#include "SDL.h"
#include "MathUtils.h"
void Sprite::Draw(SDL_Renderer* rend, const Vec2& cameraPos, Vec2 scale, int r, int g, int b, int a)
{	
	if (scale.x == 1)
		destR->x = (pos_.x + cameraPos.x) * scale.x;
	else
		destR->x = ((pos_.x + cameraPos.x) * scale.x);// -(1 - scale.x);//almost
	destR->y = (pos_.y + cameraPos.y) * scale.y;
	destR->w = spriteSize_.x * scale.x;
	destR->h = spriteSize_.y * scale.y;

	if (ssPos_ == Vec2(0.0f, 0.0f))
	{
		destL->w = ssSize_.x;
		destL->h = ssSize_.y;
		destL->x = ssPos_.x;
		destL->y = ssPos_.y;
	}
	else
	{
		destL->w = ssSize_.x;
		destL->h = ssSize_.y;
		destL->x = ssPos_.x;
		destL->y = ssPos_.y;
	}
	SDL_SetTextureAlphaMod(pImage_, a);
	SDL_SetTextureColorMod(pImage_, r, g, b); 
	SDL_RenderCopy(rend, pImage_, destL, destR);
}
