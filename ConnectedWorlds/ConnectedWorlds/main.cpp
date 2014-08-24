#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "FractureGame.h"

int main(int argc, char *argv[])
{

	Game* game = new FractureGame();
	game->InitSDL();
	game->Run();
	game->Clean();

	SDL_Quit();
	return 0;
}