#include "screen.h"

// Global objects
extern SDL_Surface *screen;

/* Draw rectange with size and color */
void draw_rectangle(int x, int y, int w, int h, int color){
	SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Fill rect with color
    SDL_FillRect(screen, &rect, color);
}

/* Load texture into surface */
SDL_Surface* load_texture(char *path){
	return IMG_Load(path); // Loading image into surface pointer
}

/* Draw surface with size and color */
void draw_surface(SDL_Surface *surface, int x, int y, int w, int h, int color){
	SDL_Rect dest; // Pos of surface
	dest.x = x;
	dest.y = y;

	// Drawing surface
	SDL_BlitSurface(surface, NULL, screen, &dest);
}

/* Drawing surface, but with frame animation */
void draw_animation_surface(SDL_Surface *surface, int x, int y, int w, int h, int color, int numofframes, int frame){
	SDL_Rect dest; // Pos of surface
	dest.x = x;
	dest.y = y;

	// Drawing surface
	SDL_BlitSurface(surface, NULL, screen, &dest);
}