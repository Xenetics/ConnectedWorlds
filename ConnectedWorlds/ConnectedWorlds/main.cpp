#include <stdlib.h>
#include <time.h>
#include "SDL.h"

int main(int argc, char *argv[])
{
	SDL_Surface* Surf_Display;

	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;
	SDL_CreateWindowAndRenderer(0, 0, SDL_WINDOW_FULLSCREEN_DESKTOP, &sdlWindow, &sdlRenderer);

	SDL_SetRenderDrawColor(sdlRenderer, 0, 0, 0, 255);
	SDL_RenderClear(sdlRenderer);
	SDL_RenderPresent(sdlRenderer);


	SDL_Quit();
	return 0;
}