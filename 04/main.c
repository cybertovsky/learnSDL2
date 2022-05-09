#include <SDL2/SDL.h>

int main(int argc, char ** argv)
{
    int quit = 0;
    SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("My SDL Empty Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, 0);
    // SDL_SetWindowFullscreen(window, 1);
    SDL_ShowCursor(SDL_DISABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    int x=0;
    int y=0;
    int speed=5;
    
    while(!quit){
        // key event
        while(SDL_PollEvent(&event) > 0){
            if (event.type == SDL_QUIT){
                quit = 1;
            }
            if (event.type == SDL_KEYDOWN)
            {
                switch (event.key.keysym.scancode)
                {
                    case SDL_SCANCODE_W:
                        y-=speed;
                        break;
                    case SDL_SCANCODE_S:
                        y+=speed;
                        break;
                    case SDL_SCANCODE_A:
                        x-=speed;
                        break;
                    case SDL_SCANCODE_D:
                        x+=speed;
                        break;
                }
            }
        }

        // looping
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_Rect rectangle;
        rectangle.x = 0;
        rectangle.y = 0;
        rectangle.w = 640;
        rectangle.h = 480;
        SDL_RenderFillRect(renderer, &rectangle);

        SDL_SetRenderDrawColor(renderer, 255, 255,255, 255);
        SDL_Rect rectangle2;
        rectangle2.x = x;
        rectangle2.y = y;
        rectangle2.w = 50;
        rectangle2.h = 50;
        SDL_RenderFillRect(renderer, &rectangle2);
        // SDL_RenderDrawRect(renderer, &rectangle);


        SDL_RenderPresent(renderer);
        // fps
        SDL_Delay(1000 / 60);
    }

    // destroy
    SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}