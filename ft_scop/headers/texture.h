#ifndef _TEXTURE_
#define _TEXTURE_
#include "sdl_tools.h"

typedef struct s_texture
{
	char		*img_src;
	unsigned char	*raw;
	unsigned int	width;
	unsigned int	height;
	unsigned int	bpp;
	unsigned int	compression;
	unsigned int	size;
	SDL_Surface *surface;
	GLuint		id_texture;
} texture_t;

texture_t *new_texture(char *image_source);
void delete_texture(texture_t *texture);
SDL_Surface *load_bmp(texture_t *texture);
int	load_texture(texture_t *texture);

#endif