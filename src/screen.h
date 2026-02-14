/* copyright (c) 2026 mykyta polishyk, see LICENSE file for more info */

#ifndef SCREEN_H
#define SCREEN_H

// Sprites
enum {
	tee_walk1=0,
	tee_walk2,
	gun,
	shotgun,
	grenade,
	rifle
};

extern void draw_rectangle(int x, int y, int w, int h, int color); // Draw rectange with size and color

#endif