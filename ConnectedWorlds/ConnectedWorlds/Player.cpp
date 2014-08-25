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
}

void UpdateCurrAnimation()
{

}

