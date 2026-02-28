/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "game_client.h"
#include "../screen.h"
#include "stdio.h"

// Global objects
extern SDL_Surface *Screen;

GameCore::GameCore(){
	return;
}

MenuState GameCore::Loop(){
	SDL_FillRect(Screen, NULL, SDL_MapRGB(Screen->format, 0, 0, 0)); // Cleaning screen

	SDL_PollEvent(&Event);
    switch (Event.type) { // Listening events
        case SDL_KEYDOWN:
            printf("The %s key was pressed!\n",
                   SDL_GetKeyName(Event.key.keysym.sym));
            break;
        case SDL_QUIT:
        	SDL_Quit();
            exit(0);
    }
    // Draw logo with animation
    DrawTee(0,0, walk_left ,SDL_MapRGB(Screen->format, 255, 0, 0));
    DrawTee(60,0, walk_right ,SDL_MapRGB(Screen->format, 255, 0, 0));
    DrawTee(0,60, idle_left ,SDL_MapRGB(Screen->format, 255, 0, 0));
    DrawTee(60,60, idle_right ,SDL_MapRGB(Screen->format, 255, 0, 0));
	SDL_Flip(Screen);
	SDL_Delay(16); // 60 fps
	return online;
}