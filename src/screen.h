/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "types.h"

#ifndef SCREEN_H
#define SCREEN_H

// Sprites
enum {
	tee_walk1=0,
	tee_walk2,
	tee_idle,
	gun,
	shotgun,
	grenade,
	rifle
};

// GFX important functions
extern void draw_rectangle(int x, int y, int w, int h, int color); // Draw rectange with size and color
extern SDL_Surface* load_texture(char *path); // Load texture into surface
extern void draw_surface(SDL_Surface *surface, int x, int y, int w, int h, int color); // Draw surface with size and color
extern void draw_animation_surface(SDL_Surface *surface, int x, int y, int w, int h, int color, int numofframes, int frame); // Drawing surface, but with frame animation (Can be helpfull in animations)
// Game GFX functions
extern void draw_tee(int x, int y, player_state state, int color);

#endif