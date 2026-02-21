/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "stdio.h"
#include "string.h"

#include "screen.h"
#include "version.h"
#include "network.h"
#include "types.h"
#include "game/game_client.h"

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

// Global objects
SDL_Surface *Screen;
NetAddr ConnectAddr;
// Time
Uint32 CurrentTime;
Uint32 PrevTime;

GameCore *Game;

void client_main(){
	// Initialization of objects
	Game = new GameCore(); 

	MenuState state=online;
	// Initialization of SDL
	if (SDL_Init(SDL_INIT_AUDIO|SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "Failed to initializate SDL");
        exit(1);
	}	
	// Initialization of SDL_image
	int Flags = IMG_INIT_PNG;
	if ( !( IMG_Init(Flags) & Flags ) ) {
	    fprintf(stderr, "Failed to initializate SDL image");
        exit(1);
	}
	// Loading data
	LoadSprites();
	// Creating window
	Screen = SDL_SetVideoMode(800, 600, 32, SDL_SWSURFACE);
	SDL_WM_SetCaption("Teewars Legacy milestone ", NULL);

	while (true){
		switch (state){
			case online:
				state = Game->Loop();
				break;
		}
	}
	// Removing objects
	delete Game;
    SDL_Quit(); // Closing window

}