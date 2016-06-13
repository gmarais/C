#ifndef _GRAPHIC_
#define _GRAPHIC_

#define IMG_NBR 17

#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>

typedef struct graphic_data
{
	SDL_Surface *screen;
	SDL_Surface *bg_img;
	SDL_Surface *icon_img;
	SDL_Surface *img[IMG_NBR];
	TTF_Font *police;
	float bg_offset;
} graphic_data_t;

extern graphic_data_t gd;

int load_images();
void draw();
void draw_bg();
void draw_ui();

#endif
