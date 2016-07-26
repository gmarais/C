#include "libft.h"
#include "texture.h"
#include <stdio.h>

static void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	const int bpp = surface->format->BytesPerPixel;
	Uint8 *p;

	p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
	if (bpp == 1)
		*p = pixel;
	else if (bpp == 2)
		*(Uint16 *)p = pixel;
	else if (bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
		{
			p[0] = (pixel >> 16) & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = pixel & 0xff;
		}
		else
		{
			p[0] = pixel & 0xff;
			p[1] = (pixel >> 8) & 0xff;
			p[2] = (pixel >> 16) & 0xff;
		}
	}
	else if (bpp == 4)
		*(Uint32 *)p = pixel;
}

static void	fill_surface(SDL_Surface * surface, texture_t *texture)
{
	Uint32 pixel;
	Uint8 p[4];
	int i;
	int j;
	int pos[2];

	i = 0;
	while (i < texture->size -2)
	{
		j = 0;
		while (j < texture->bpp / 8)
		{
			p[j] = *(Uint8 *)&(texture->raw[i + j]);
			j++;
		}
		pos[0] = (i / j) % texture->width;
		pos[1] = i / (j * texture->width);
		putpixel(surface, pos[0], pos[1], *(Uint32 *)p);
		i += j;
	}
}

static int		bmp_file_to_raw_texture(texture_t *texture)
{
	char			header[55];
	unsigned int	position;
	FILE			*fp;

	if ((fp = fopen(texture->img_src, "rb")) <= 0
		|| fread(header, 54, 1, fp) != 1
		|| ft_strncmp(header, "BM", 2))
		return -1;
	position = *(int *)&(header[0x0A]) ? *(int *)&(header[0x0A]) : 54;
	texture->bpp = *(int *)&(header[0x1C]);
	texture->size = *(int *)&(header[0x22]);
	texture->width = *(int *)&(header[0x12]);
	texture->height = *(int *)&(header[0x16]);
	texture->compression = *(int *)&(header[0x1E]);
	if (!texture->size)
		texture->size = texture->width * texture->height * (texture->bpp / 8);
	fseek(fp, position, SEEK_SET);
	texture->raw = (unsigned char *)ft_memalloc(sizeof(char) * texture->size);
	int ret = fread(texture->raw, texture->size, 1, fp);
	if (!texture->raw || ret != 1)
		return -1;
	fclose(fp);
	return 0;
}

SDL_Surface *load_bmp(texture_t *texture)
{
	SDL_Surface *s;
	int i;

	if (bmp_file_to_raw_texture(texture) != 0)
		return NULL;
	s = SDL_CreateRGBSurface(0, texture->width, texture->height, 32
		, 0xff000000
		, 0x00ff0000
		, 0x0000ff00
		, 0x000000ff);
	fill_surface(s, texture);
	return s;
}
