#include "SpriteAnimation.h"

																// these need to be b2Vec2's
SpriteAnimation::SpriteAnimation(SDL_Texture* image, b2Vec2 cellSize, b2Vec2 frames_xy, b2Vec2 sheetSize, float frameRate, bool loop, b2Vec2 pos) :
Sprite(image, pos, cellSize),
frameRate_(frameRate),
loop_(loop),
playing_(false),
currFrame_(0),
frameTimer_(0.0f)
{
	srcRect_ = SDL_Rect();
	/*
	sheetSize.x = image->clip_rect.w / cellSize.x;  // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>THIS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	sheetSize.y = image->clip_rect.h / cellSize.y;
	*/
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

void SpriteAnimation::Draw(SDL_Renderer* rend, const b2Vec2& cameraPos) // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>THIS>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
{
	/*
	SDL_SetAlpha(pImage_, SDL_SRCALPHA, alpha_);
	SDL_Rect destR;
	destR.x = (Sint16)pos_.x - (Sint16)(cellWidth_ / 2);
	destR.y = (Sint16)pos_.y - (Sint16)(cellHeight_ / 2);

	SDL_BlitSurface(pImage_, &srcRect_, pSurfaceToDrawOn, &destR);
	*/
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