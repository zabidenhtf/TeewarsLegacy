/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */
#include "SDL/SDL.h"
#include "../types.h"
#ifndef GAME_H
#define GAME_H

// Game class define
class GameCore{
public:
	GameCore();
	MenuState Loop();
private:
	SDL_Event Event;
};

#endif