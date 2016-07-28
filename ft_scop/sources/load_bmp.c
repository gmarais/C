/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_bmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "texture.h"
#include <stdio.h>
#include <sys/stat.h>

static void	putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
	const int	bpp = surface->format->BytesPerPixel;
	Uint8		*p;

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

static void	fill_surface(SDL_Surface *surface, t_texture *texture)
{
	Uint32	pixel;
	Uint8	p[4];
	int		i;
	int		j;
	int		pos[2];

	i = 0;
	while (texture->size > 0 && i < texture->size - 2)
	{
		j = 0;
		while (j < texture->bpp / 8)
		{
			p[j] = *(Uint8 *)&(texture->raw[i + j]);
			j++;
		}
		pos[0] = (i / j) % texture->width;
		pos[1] = i / (j * texture->width);
		if (pos[0] <= surface->w && pos[1] <= surface->h)
			putpixel(surface, pos[0], pos[1], *(Uint32 *)p);
		i += j;
	}
}

static int	read_header(t_texture *texture, unsigned int *position, FILE **fp)
{
	char			header[55];

	if ((*fp = fopen(texture->img_src, "rb")) <= 0
		|| fread(header, 54, 1, *fp) != 1
		|| ft_strncmp(header, "BM", 2))
		return (-1);
	*position = *(int *)&(header[0x0A]) ? *(int *)&(header[0x0A]) : 54;
	texture->bpp = *(int *)&(header[0x1C]);
	texture->size = *(int *)&(header[0x22]);
	texture->width = *(int *)&(header[0x12]);
	texture->height = *(int *)&(header[0x16]);
	texture->compression = *(int *)&(header[0x1E]);
	if (texture->size > texture->width * texture->height * (texture->bpp / 8))
		return (-1);
	if (!texture->size)
		texture->size = texture->width * texture->height * (texture->bpp / 8);
	return (0);
}

static int	bmp_file_to_raw_texture(t_texture *texture, size_t fsize)
{
	unsigned int	position;
	FILE			*fp;
	int				ret;

	if (read_header(texture, &position, &fp))
		return (-1);
	fseek(fp, position, SEEK_SET);
	texture->raw = (unsigned char *)ft_memalloc(sizeof(char) * texture->size);
	if (!texture->raw
		|| texture->size > position + fsize
		|| (ret = fread(texture->raw, texture->size, 1, fp)) != 1)
		return (-1);
	fclose(fp);
	return (0);
}

SDL_Surface	*load_bmp(t_texture *texture)
{
	SDL_Surface	*s;
	int			i;
	struct stat	st;

	if (stat(texture->img_src, &st) || st.st_size < 54)
		return (NULL);
	if (bmp_file_to_raw_texture(texture, st.st_size) != 0)
		return (NULL);
	s = SDL_CreateRGBSurface(0, texture->width, texture->height, 32
		, 0xff000000
		, 0x00ff0000
		, 0x0000ff00
		, 0x000000ff);
	fill_surface(s, texture);
	return (s);
}
