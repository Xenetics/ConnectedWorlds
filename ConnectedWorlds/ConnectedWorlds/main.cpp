#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "FractureGame.h"

int main(int argc, char *argv[])
{

	FractureGame* game = new FractureGame();
	game->init();
	SDL_Quit();
	return 0;
}