#include "screen.h"
#include "SDL/SDL.h"

// Global objects
extern SDL_Surface *screen;

// Draw rectange with size and color
void draw_rectangle(int x, int y, int w, int h, int color){
	SDL_Rect rect;
    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

    // Fill rect with color
    SDL_FillRect(screen, &rect, color);
}