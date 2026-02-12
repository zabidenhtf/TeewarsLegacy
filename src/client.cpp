/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "stdio.h"
#include "SDL/SDL.h"

// Global objects
SDL_Surface *screen;

void client_main(){
	// Initialization of SDL
	if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Failed to initializate SDL");
        exit(1);
	}	

	// Creating window
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Teewars Legacy", NULL);

	SDL_Delay(2000);

    SDL_Quit(); // Closing window

}