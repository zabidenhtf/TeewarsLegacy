/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "types.h"

#ifndef SCREEN_H
#define SCREEN_H

// Sprites global pointers
// Tees tileset
extern SDL_Surface *tee_tileset_left;
extern SDL_Surface *tee_tileset_right;
// Weapons tileset
extern SDL_Surface *weapons_tileset_left;
extern SDL_Surface *weapons_tileset_right;

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
extern void load_sprites(); // Load sprites into pointers
extern void draw_rectangle(int x, int y, int w, int h, int color); // Draw rectange with size and color
extern SDL_Surface* load_texture(char *path); // Load texture into surface
extern void draw_surface(SDL_Surface *surface, int x, int y, int color); // Draw surface with size and color
extern void draw_animation_surface(SDL_Surface *surface, int x, int y, int color, int numofframes, int frame); // Drawing surface, but with frame animation (Can be helpfull in animations)
// Game GFX functions
extern void draw_tee(int x, int y, player_state state, int color);

#endif