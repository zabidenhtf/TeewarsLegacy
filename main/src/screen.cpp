#include "screen.h"

// Global objects
extern SDL_Surface *Screen;

// Tees tileset
SDL_Surface *TeeTilesetLeft;
SDL_Surface *TeeTilesetRight;
// Weapons tileset
SDL_Surface *WeaponsTilesetLeft;
SDL_Surface *WeaponsTilesetRight;
// Logo animation
SDL_Surface *LogoAnimation;

/* Load sprites into pointers */
void LoadSprites(){
	TeeTilesetLeft = LoadTexture("data/tees_left.png");
	TeeTilesetRight = LoadTexture("data/tees_right.png");
	WeaponsTilesetLeft = LoadTexture("data/weapons_left.png");
	WeaponsTilesetRight = LoadTexture("data/weapons_right.png");
	LogoAnimation = LoadTexture("data/logo.png");
}

/* Draw rectange with size and color */
void DrawRectangle(int x, int y, int w, int h, int color){
	SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Fill rect with color
    SDL_FillRect(Screen, &rect, color);
}

/* Load texture into surface */
SDL_Surface* LoadTexture(char *path){
	return IMG_Load(path); // Loading image into surface pointer
}

/* Draw surface with size and color */
void DrawSurface(SDL_Surface *surface, int x, int y, int color){
	SDL_Rect dest; // Pos of surface
	dest.x = x;
	dest.y = y;

	// Drawing surface
	SDL_BlitSurface(surface, NULL, Screen, &dest);
}

/* Drawing surface, but with frame animation */
void DrawAnimationSurface(SDL_Surface *surface, int x, int y, int color, int numofframes, int frame){
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
	SDL_BlitSurface(surface, &src, Screen, &point2);
}

/* Drawing player with color, and animation */
void DrawTee(int x, int y, PlayerState state, int color){
	switch (state){
		case walk_left:
			DrawAnimationSurface(TeeTilesetLeft, x, y, color, 4, tee_walk1);
			break;
		case walk_right:
			DrawAnimationSurface(TeeTilesetRight, x, y, color, 4, tee_walk1);
			break;
		case idle_left:
			DrawAnimationSurface(TeeTilesetLeft, x, y, color, 4, tee_idle);
			break;
		case idle_right:
			DrawAnimationSurface(TeeTilesetRight, x, y, color, 4, tee_idle);
			break;
		case fall_left:
			DrawAnimationSurface(TeeTilesetLeft, x, y, color, 4, tee_jump);
			break;
		case fall_right:
			DrawAnimationSurface(TeeTilesetRight, x, y, color, 4, tee_jump);
			break;
	}
}
void DrawMap(int x, int y, Map *object, int color){
    // Draw outline
    for(int i=0;i<object->vertices_n;i++){
	    int next = (i+1)%object->vertices_n;
	    lineColor(Screen,
	             object->vertices[i].x + x, object->vertices[i].y + y,
	             object->vertices[next].x + x, object->vertices[next].y + y,
	             color);
	}
}