/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "types.h"

#ifndef SCREEN_H
#define SCREEN_H

// Sprites global pointers
// Tees tileset
extern SDL_Surface *TeeTilesetLeft;
extern SDL_Surface *TeeTilesetRight;
// Weapons tileset
extern SDL_Surface *WeaponsTilesetLeft;
extern SDL_Surface *WeaponsTilesetRight;
// Logo animation
extern SDL_Surface *LogoAnimation; // This animation have 20 frames

enum{ // Tee tileset
	tee_idle=1,
	tee_walk1,
	tee_walk2,
	tee_jump
};

enum{ // Weapons tileset
	gun=1,
	rifle,
	shotgun,
	grenade
};

// GFX important functions
extern void LoadSprites(); // Load sprites into pointers
extern void DrawRectangle(int x, int y, int w, int h, int color); // Draw rectange with size and color
extern SDL_Surface* LoadTexture(char *path); // Load texture into surface
extern void DrawSurface(SDL_Surface *surface, int x, int y, int color); // Draw surface with size and color
extern void DrawAnimationSurface(SDL_Surface *surface, int x, int y, int color, int numofframes, int frame); // Drawing surface, but with frame animation (Can be helpfull in animations)
// Game GFX functions
extern void DrawTee(int x, int y, PlayerState state, int color); // Drawing player with color, and animation

#endif