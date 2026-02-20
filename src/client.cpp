/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "stdio.h"
#include "string.h"

#include "screen.h"
#include "version.h"
#include "network.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

// Global objects
SDL_Surface *screen;
NetAddr connect_server;

void client_main(){
	// Initialization of SDL
	if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Failed to initializate SDL");
        exit(1);
	}	
	// Initialization of SDL_image
	int flags = IMG_INIT_PNG;
	if ( !( IMG_Init(flags) & flags ) ) {
	    fprintf(stderr, "Failed to initializate SDL image");
        exit(1);
	}
	// Loading data
	load_sprites();
	// Creating window
	screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Teewars Legacy milestone ", NULL);

	draw_animation_surface(tee_tileset_left,0,0,SDL_MapRGB(screen->format, 255, 255, 255), 4 , tee_walk1);
	SDL_Flip(screen); 

	SDL_Delay(2000);

    SDL_Quit(); // Closing window

}