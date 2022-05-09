#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
	SDL_Init(SDL_INIT_VIDEO);
	SDL_Window * window = SDL_CreateWindow("My SDL Empty Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    // SDL_SetWindowFullscreen(window, 1);
    SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}