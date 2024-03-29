#include "window.h"
#include <SDL2/SDL.h>
#include <time.h>

SDL_Renderer *renderer;
SDL_Window *main_window;
int window_width;
int window_height;

unsigned long get_time_usec()
{
    struct timespec t;

    clock_gettime(CLOCK_MONOTONIC_RAW, &t);
    return (t.tv_sec * 1000000 + t.tv_nsec / 1000);
}

int  init_window()
{
	Uint32 flags;
    flags = SDL_WINDOW_RESIZABLE|SDL_WINDOW_HIDDEN;
    //flags = SDL_WINDOW_HIDDEN;
    unsigned long t1 = get_time_usec();
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) < 0) { fprintf(stderr, "\nUnable to initialize SDL:  %s\n", SDL_GetError()); }

    unsigned long t2 = get_time_usec();
    printf("Time it took to initialize SDL2: %ldms\n", (t2 - t1)/1000);
    
    if (SDL_CreateWindowAndRenderer(0, 0, flags, &main_window, &renderer) < 0) {
        SDL_Log("SDL_CreateWindowAndRenderer() failed: %s\n", SDL_GetError());
        return 1;
	}
    SDL_SetWindowTitle(main_window, "game_window");
    SDL_SetWindowPosition(main_window, 0,0);
    SDL_SetWindowSize(main_window, GAME_WINDOW+PANEL_WINDOW, GAME_WINDOW + STATUS_LINE);
    SDL_GetWindowSize(main_window, &window_width, &window_height); 
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_ShowWindow(main_window);

    int imgFlags = IMG_INIT_PNG;
    if (!(IMG_Init(imgFlags) & imgFlags)) 
    {
        printf("\nUnable to initialize sdl_image:  %s\n", IMG_GetError());
        return 1;
    }
    TTF_Init();

    
    unsigned long t3 = get_time_usec();
    printf("Time it took to initialize SDL2 modules (img, window, renderer): %ldms\n ", (t3 - t1)/1000);
    
    return 0;
}

void clear_window()
{
     SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

unsigned int color(int r, int g, int b, int a) {
	return (a << 24) | (b << 16) | (g << 8) | r;
}

