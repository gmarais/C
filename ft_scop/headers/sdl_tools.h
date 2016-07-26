#ifndef _SDL_TOOLS_
#define _SDL_TOOLS_
#include <SDL2/SDL.h>
#include <GL/glew.h>

SDL_Surface	*copy_sdl_surface(SDL_Surface *surface);
SDL_Surface* invert_pixels(SDL_Surface *s);

#endif