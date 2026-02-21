#include "screen.h"

// Global objects
extern SDL_Surface *screen;

// Tees tileset
SDL_Surface *tee_tileset_left;
SDL_Surface *tee_tileset_right;
// Weapons tileset
SDL_Surface *weapons_tileset_left;
SDL_Surface *weapons_tileset_right;
// Logo animation
SDL_Surface *logo_animation;

/* Load sprites into pointers */
void load_sprites(){
	tee_tileset_left = load_texture("data/tees_left.png");
	tee_tileset_right = load_texture("data/tees_right.png");
	weapons_tileset_left = load_texture("data/weapons_left.png");
	weapons_tileset_right = load_texture("data/weapons_right.png");
	logo_animation = load_texture("data/logo.png");
}

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
void draw_surface(SDL_Surface *surface, int x, int y, int color){
	SDL_Rect dest; // Pos of surface
	dest.x = x;
	dest.y = y;

	// Drawing surface
	SDL_BlitSurface(surface, NULL, screen, &dest);
}

/* Drawing surface, but with frame animation */
void draw_animation_surface(SDL_Surface *surface, int x, int y, int color, int numofframes, int frame){
	SDL_Rect point2;
	point2.x = x;
	point2.y = y;

	// Crop frame 
	SDL_Rect src;
	src.x = 0;
	src.y = (frame-1)*(surface->h/numofframes);
	src.w = surface->w;
	src.h = surface->h / numofframes;

	// Drawing surface
	SDL_BlitSurface(surface, &src, screen, &point2);
}