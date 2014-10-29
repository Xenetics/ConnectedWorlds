#pragma once

#include "Sprite.h"
#include <map>
#include <string>

class SpriteAnimation : public Sprite
{
protected:
	struct AnimationData
	{
		Uint16 startFrame;
		float frameRate;
		Uint16 numFrames;
	};

	Vec2 cellSize_; // x = cellWidth, y = cellHeight
	// cellWidth // how wide each animation frame is
	// cellHeight // how tall each animation frame is

	Vec2 frames_xy_; // x = numFrames, y = startFrame
	// numFrames	// num of frames in animation
	// startFrame	// frame animation starts at

	Vec2 sheetSize_; // x = framesWide, y = framesHigh
	// framesWide // how many cells wide sheet is
	// framesHigh // how many cells high sheet is

	Uint16 currFrame_; // holds what frame we are at

	float frameRate_;
	float frameTimer_;

	bool playing_;
	bool loop_;

	SDL_Rect srcRect_;

	void updateSrcRect();
	void updateCurrFrame(float deltaTime);

	//std::map<std::string, AnimationData> anims_;
	void setCurrAnim(std::string animation);

public:
	SpriteAnimation() : Sprite(), frameRate_(0), loop_(0), playing_(true), currFrame_(0), frameTimer_(0), cellSize_(Vec2(0.0f, 0.0f)), sheetSize_(Vec2(0.0f, 0.0f)), frames_xy_(Vec2(0.0f, 0.0f))
	{
	}
														
	SpriteAnimation(SDL_Texture* image, Vec2 pos, Vec2 cellSize, Vec2 frames_xy, Vec2 sheetSize, float frameRate, bool loop);

	virtual void Update(float deltaTime);

	virtual void Draw(SDL_Renderer* rend, const Vec2& cameraPosz, int r = 255, int g = 255, int b = 255, int a = 255);

	void Play(bool loop = false)
	{
		playing_ = true;
		loop_ = loop;
	}

	//Accessors
	float GetRight() { return pos_.x + cellSize_.x / 2.0f; }
	float GetLeft() { return pos_.x - cellSize_.x / 2.0f; }
	float GetTop() { return pos_.y - cellSize_.y / 2.0f; }
	float GetBottom() { return pos_.y + cellSize_.y / 2.0f; }

	void SetStartFrame(Uint16 startFrame)
	{
		frames_xy_.y = startFrame;
		currFrame_ = startFrame;
	}

	void SetNumFrames(Uint16 numFrames)
	{
		frames_xy_.x = numFrames;
	}

	void Stop()
	{
		playing_ = false;
	}

	Uint16 GetWidth()
	{
		return cellSize_.x;
	}

	Uint16 GetHeight()
	{
		return cellSize_.y;
	}

	void SetLoop(bool loop)
	{
		loop_ = loop;
	}
};

