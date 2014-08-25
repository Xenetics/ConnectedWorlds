#pragma once
#include "SpriteAnimation.h"
#include "Globals.h"
#include <math.h>

class Player : public SpriteAnimation
{
public:
	Player(SDL_Texture* image, Vec2 pos, Vec2 cellSize, Vec2 frames_xy, Vec2 sheetSize, float frameRate, bool loop) : SpriteAnimation(image, pos, cellSize, frames_xy, sheetSize, frameRate, loop)
	{
		UpdateCurrAnimation();
		Play(true);
	}
	~Player();

	Vec2 velocity;
	Vec2 acc = Vec2(GRAVITY.x, GRAVITY.y);
	float playerSpeed = 100.0f;
	float jumpSpeed = 100.0f;
	enum animNames{ ANIM_RUN_RIGHT, ANIM_RUN_LEFT, ANIM_JUMP_RIGHT, ANIM_JUMP_LEFT, ANIM_IDLE_RIGHT, ANIM_IDLE_LEFT };
	animNames currentAnim = ANIM_RUN_RIGHT;

	void UpdateCurrAnimation();
	virtual void Update(float deltaTime);
	virtual void OnKeyDown(Uint16 key);
	virtual void OnKeyUp(Uint16 key);
};

