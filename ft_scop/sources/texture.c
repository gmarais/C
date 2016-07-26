#include <stdlib.h>
#include "texture.h"
#include "sdl_tools.h"

texture_t *new_texture(char *image_source)
{
	texture_t *texture;

	texture = (texture_t *)malloc(sizeof(texture_t));
	texture->img_src = image_source;
	texture->surface = NULL;
	texture->raw = NULL;
	texture->id_texture = 0;
	return texture;
}

void delete_texture(texture_t *texture)
{
	if (glIsTexture(texture->id_texture) == GL_TRUE)
		glDeleteTextures(1, &texture->id_texture);
	if (texture->raw)
		free(texture->raw);
}

static int set_formats(GLenum *f, GLenum *intern_f, texture_t *texture)
{
	if (texture->surface->format->BytesPerPixel == 3)
	{
		*intern_f= GL_RGB;
		if (texture->surface->format->Rmask == 0xff)
			*f = GL_RGB;
		else
			*f = GL_BGR;
	}
	else if (texture->surface->format->BytesPerPixel == 4)
	{
		*intern_f = GL_RGBA;
		if(texture->surface->format->Rmask == 0xff)
			*f = GL_RGBA;
		else
			*f = GL_BGRA;
	}
	else
		return -1;
	return 0;
}

static int load_image_in_texture(texture_t *texture)
{
	GLenum intern_format;
	GLenum format;

	if (set_formats(&format, &intern_format, texture) != 0)
		return -1;
	glTexImage2D(GL_TEXTURE_2D, 0
		, intern_format
		, texture->surface->w
		, texture->surface->h
		, 0
		, format
		, GL_UNSIGNED_BYTE
		, texture->surface->pixels);
	return 0;
}

int	load_texture(texture_t *texture)
{
	SDL_Surface *surface;

	surface = load_bmp(texture);
	if (surface == NULL)
		return -1;
	if (glIsTexture(texture->id_texture) == GL_TRUE)
		glDeleteTextures(1, &texture->id_texture);
	texture->surface = surface;
	glGenTextures(1, &texture->id_texture);
	glBindTexture(GL_TEXTURE_2D, texture->id_texture);
	if (load_image_in_texture(texture))
		return -1;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(texture->surface);
	texture->surface = NULL;
	return 0;
}