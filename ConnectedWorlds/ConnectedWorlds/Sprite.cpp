#include "Sprite.h"
#include "SDL.h"


void Sprite::Draw(SDL_Renderer* rend, const b2Vec2& cameraPos)
{
	//maybe we dont need this SDL_RLEACCEL 
	
	SDL_Rect destR;
	destR.x = pos_.x;
	destR.y = pos_.y;
	destR.w = 1280;
	destR.h = 720;


	SDL_RenderCopy(rend, pImage_, NULL, &destR);

	SDL_RenderPresent(rend);
}
