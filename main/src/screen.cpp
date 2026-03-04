#include "screen.h"
#include "math.h"

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
// Armor and health icons tileset
SDL_Surface *HealthTileset;
SDL_Surface *ArmorTileset;
// Clouds tileset
SDL_Surface *CloudsTileset;

/* Load sprites into pointers */
void LoadSprites(){
	TeeTilesetLeft = LoadTexture("data/tees_left.png");
	TeeTilesetRight = LoadTexture("data/tees_right.png");
	WeaponsTilesetLeft = LoadTexture("data/weapons_left.png");
	WeaponsTilesetRight = LoadTexture("data/weapons_right.png");
	LogoAnimation = LoadTexture("data/logo.png");
	HealthTileset = LoadTexture("data/health.png");
	ArmorTileset = LoadTexture("data/armor.png");
	CloudsTileset = LoadTexture("data/clouds.png");
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
/* Draw map with game objects (like pickups and etc) */
void DrawMap(int x, int y, Map *object, int color){
    // Draw outline
    for(int i=0;i<object->vertices_n;i++){
	    int next = (i+1)%object->vertices_n;
	    lineColor(Screen,
	             object->vertices[i].x + x, object->vertices[i].y + y,
	             object->vertices[next].x + x, object->vertices[next].y + y,
	             color);
	}
	// Draw objects
	for(int i=0;i<object->objects_n;i++){
		// For debug we use a tee icon
		DrawAnimationSurface(TeeTilesetLeft, object->objects[i].x, object->objects[i].y, SDL_MapRGBA(Screen->format, 255, 255, 255, 255),4,1);
	}
}

/* Drawing clouds with sin animation */
void DrawClouds(){
    for (int i=0; i<(800/64)+1; i++){
        int n;
        // Selection of sinus direction
        if (i%2 == 0){
            n = -1;
        }
        else{
            n = 1;
        }
        // Drawing surface
        DrawAnimationSurface(CloudsTileset, i*64, 20-sin(SDL_GetTicks()/500.0f)*5*n, SDL_MapRGBA(Screen->format, 255, 255, 255, 255), 2, 1+i%2);
    }
}