/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "game_client.h"
#include "../screen.h"
#include "stdio.h"

// Global objects
extern SDL_Surface *Screen;
int Anim=1;

GameCore::GameCore(){
	return;
}

MenuState GameCore::Loop(){
	SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0)); // Cleaning screen

	SDL_PollEvent(&Event);
	Anim++;
    switch (Event.type) { // Listening events
        case SDL_KEYDOWN:
            printf("The %s key was pressed!\n",
                   SDL_GetKeyName(Event.key.keysym.sym));
            break;
        case SDL_QUIT:
        	SDL_Quit();
            exit(0);
    }
    if (Anim == 20){
    	Anim = 1;
    }
    // Draw logo with animation
    DrawAnimationSurface(LogoAnimation,0,0,SDL_MapRGB(Screen->format, 255, 255, 255), 20 , Anim);
	SDL_Flip(Screen);
	return online;
}