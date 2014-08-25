#pragma once
#include "SpriteAnimation.h"
#include <math.h>

class Player : public SpriteAnimation
{
public:
	Player(SDL_Texture* image, Vec2 pos, Vec2 cellSize, Vec2 frames_xy, Vec2 sheetSize, float frameRate, bool loop) : SpriteAnimation(image, pos, cellSize, frames_xy, sheetSize, frameRate, loop)
	{

	}
	~Player();

	Vec2 velocity;
	float playerSpeed = 150;

	virtual void Update(float deltaTime);
	virtual void OnKeyDown(Uint16 key);
	virtual void OnKeyUp(Uint16 key);
};

