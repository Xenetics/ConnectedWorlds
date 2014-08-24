#include <stdlib.h>
#include <time.h>
#include "SDL.h"
#include "Game.h"

int main(int argc, char *argv[])
{

	Game* game = new Game();
	game->InitSDL();
	game->InitGame();
	game->Run();
	game->Clean();
	SDL_Quit();
	return 0;
}