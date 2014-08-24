#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "FractureGame.h"

int main(int argc, char *argv[])
{

	Game* game = new FractureGame();

	SDL_Quit();
	return 0;
}