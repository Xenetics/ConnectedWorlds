#include "SpriteAnimation.h"

																// these need to be b2Vec2's
SpriteAnimation::SpriteAnimation(SDL_Texture* image, Vec2 pos, Vec2 cellSize, Vec2 frames_xy, Vec2 sheetSize, float frameRate, bool loop) :
Sprite(image, pos, cellSize), frameRate_(frameRate), loop_(loop), playing_(true), currFrame_(0), frameTimer_(0.0f), cellSize_(cellSize), sheetSize_(sheetSize), frames_xy_(frames_xy)
{
	srcRect_ = SDL_Rect();
	
	int w, h;
	SDL_QueryTexture(image, NULL, NULL, &w, &h);

	sheetSize_.x =  w / cellSize.x;  
	sheetSize_.y = h / cellSize.y;

	frameRate_ = 1 / frameRate_;
	updateSrcRect();
}

void SpriteAnimation::Update(float deltaTime)
{
	updateSrcRect();
	updateCurrFrame(deltaTime);
}

void SpriteAnimation::setCurrAnim(std::string animation)
{
	frameRate_ = anims_[animation].frameRate;
	frames_xy_.y = anims_[animation].startFrame;
	currFrame_ = frames_xy_.y;
	frames_xy_.x = anims_[animation].numFrames;
}

void SpriteAnimation::Draw(SDL_Renderer* rend, const Vec2& cameraPos) 
{
	destR->x = pos_.x - spriteSize_.x / 2;
	destR->y = pos_.y - spriteSize_.y / 2;
	destR->w = spriteSize_.x;
	destR->h = spriteSize_.y;

	SDL_RenderCopy(rend, pImage_, &srcRect_, destR);

	SDL_RenderPresent(rend);
}

void SpriteAnimation::updateSrcRect()
{
	srcRect_.x = (currFrame_ % (Uint16)sheetSize_.x) * cellSize_.y;
	srcRect_.y = (currFrame_ / (Uint16)sheetSize_.x) * cellSize_.x;
	srcRect_.w = cellSize_.x;
	srcRect_.h = cellSize_.y;
}

void SpriteAnimation::updateCurrFrame(float deltaTime)
{
	if (playing_)
	{
		frameTimer_ += deltaTime;
		SDL_Log("%f", frameTimer_);
		if (frameTimer_ > frameRate_)
		{
			frameTimer_ = frameTimer_ - frameRate_;
			currFrame_++;

			if (currFrame_ >= frames_xy_.x + frames_xy_.y)
			{
				currFrame_ = frames_xy_.y;
				if (!loop_)
				{
					playing_ = false;
				}
			}

		}
	}
}