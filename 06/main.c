#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

const int WINDOW_WIDTH = 640;
const int WINDOW_HEIGHT = 480;

struct Sprite{
    int x;
    int y;
    int w;
    int h;
    int speed;
    SDL_Texture *texture;
};

SDL_Texture *load_image(SDL_Renderer *renderer,char *path)
{
    SDL_Surface *image = IMG_Load(path);
    if (!image)
    {
        printf("IMG_Load: %s\n", IMG_GetError());
        exit(0);
    }

    Uint32 colorkey = SDL_MapRGB(image->format, 0, 0, 0);
    // enables transparency for all black pixels
    SDL_SetColorKey(image, SDL_TRUE, colorkey);
    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
    return texture;
}

void draw_sprite(SDL_Renderer *renderer, struct Sprite sprite)
{
    SDL_Rect rect = {sprite.x, sprite.y, sprite.w, sprite.h};
    SDL_RenderCopy(renderer, sprite.texture, NULL, &rect);
}

int main(int argc, char ** argv)
{
    int quit = 0;
    SDL_Event event;
	SDL_Init(SDL_INIT_VIDEO);

	SDL_Window * window = SDL_CreateWindow("My SDL Empty Window",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    // SDL_SetWindowFullscreen(window, 1);
    SDL_ShowCursor(SDL_DISABLE);

    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    struct Sprite hero={(int)WINDOW_WIDTH/2-16,(int)WINDOW_HEIGHT-64,32,32,10,load_image(renderer,"./assets/hero.bmp")};
    
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
                        hero.y-=hero.speed;
                        break;
                    case SDL_SCANCODE_S:
                        hero.y+=hero.speed;
                        break;
                    case SDL_SCANCODE_A:
                        hero.x-=hero.speed;
                        break;
                    case SDL_SCANCODE_D:
                        hero.x+=hero.speed;
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

        draw_sprite(renderer,hero);

        SDL_RenderPresent(renderer);
        // fps
        SDL_Delay(1000 / 60);
    }

    // destroy
    SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}