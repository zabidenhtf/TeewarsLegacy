/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "SDL/SDL.h"
#include "../types.h"
#include "../protocol.h"

#ifndef GAME_H
#define GAME_H

#define N_OF_CLOUDS 20

// Game class define
class GameCore{
public:
	GameCore();
	MenuState Loop();
	void DrawClouds();
private:
	SDL_Event Event;
    Map object; // For debug
};

#endif