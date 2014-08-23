#pragma once

#include "Game.h"

class FractureGame : public Game
{
private:
	void loadAssets();
	void update(float deltaTime);
	void draw();
	void onKeyDown(Uint16 key);
	void onKeyUp(Uint16 key);
	void updateCamera();

public:
	FractureGame() : Game()
	{
	}
	void BinCollisions(int tile);
	void ItemCollisions();
	void EnemyCollisions();
};
