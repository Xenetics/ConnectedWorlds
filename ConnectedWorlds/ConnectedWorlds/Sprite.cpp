#include "Sprite.h"
#include "SDL.h"


void Sprite::Draw(SDL_Surface* pSurfaceToDrawOn, const b2Vec2& cameraPos)
{
	//maybe we dont need this SDL_RLEACCEL 
	SDL_SetSurfaceAlphaMod(pImage_,  alpha);
	SDL_Rect destR;
	destR.x = (Sint16)pos_.x - (Sint16)(pImage_->clip_rect.w / 2);
	destR.y = (Sint16)pos_.y - (Sint16)(pImage_->clip_rect.h / 2);

	SDL_BlitSurface(pImage_, NULL, pSurfaceToDrawOn, &destR);
}
