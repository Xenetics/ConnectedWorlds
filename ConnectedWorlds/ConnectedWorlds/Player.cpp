#include "Player.h"


Player::~Player()
{

}

void Player::Update(float deltaTime)
{
	velocity = VectorMath::Normalize(&velocity);
	pos_ += velocity * playerSpeed * deltaTime;
	SpriteAnimation::Update(deltaTime);
	
}

void Player::OnKeyDown(Uint16 key)
{
	switch (key)
	{
	case SDL_SCANCODE_RIGHT:
		velocity.x += 1;
		break;
	case SDL_SCANCODE_LEFT:
		velocity.x -= 1;
		break;
	case SDL_SCANCODE_SPACE:
		break;
	}
	if (!playing_)
	{
		Play(true);
	}
	UpdateCurrAnimation();
}

void Player::OnKeyUp(Uint16 key)
{
	switch (key)
	{
	case SDL_SCANCODE_RIGHT:
		velocity.x = 0;
		break;
	case SDL_SCANCODE_LEFT:
		velocity.x = 0;
		break;
	case SDL_SCANCODE_SPACE:
		break;
	}
	if (!playing_)
	{
		Play(true);
	}
	UpdateCurrAnimation();
}

void Player::UpdateCurrAnimation()
{
	if ((velocity.y > 0 && velocity.x > 0) && currentAnim != ANIM_JUMP_RIGHT)
	{
		currentAnim = ANIM_JUMP_RIGHT;
		SetStartFrame(6);
	}
	else if ((velocity.y > 0 && velocity.x < 0) && currentAnim != ANIM_JUMP_LEFT)
	{
		currentAnim = ANIM_JUMP_LEFT;
		SetStartFrame(9);
	}
	else if (velocity.x > 0 && currentAnim != ANIM_RUN_RIGHT)
	{
		currentAnim = ANIM_RUN_RIGHT;
		SetLoop(false);
		SetStartFrame(0);
	}
	else if (velocity.x < 0 && currentAnim != ANIM_RUN_LEFT)
	{
		currentAnim = ANIM_RUN_LEFT;
		SetStartFrame(3);
	}
	else if (velocity.x == 0 && currentAnim == ANIM_RUN_RIGHT)
	{
		currentAnim = ANIM_IDLE_RIGHT;
		SetStartFrame(12);
	}
	else if (velocity.x == 0 && currentAnim == ANIM_RUN_LEFT)
	{
		currentAnim = ANIM_IDLE_LEFT;
		SetStartFrame(15);
	}
}

