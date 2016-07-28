/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sdl_tools.h"

SDL_Surface		*copy_sdl_surface(SDL_Surface *surface)
{
	SDL_Surface		*result;

	result = SDL_CreateRGBSurface(0,
		surface->w,
		surface->h,
		surface->format->BitsPerPixel,
		surface->format->Rmask,
		surface->format->Gmask,
		surface->format->Bmask,
		surface->format->Amask);
	return (result);
}

SDL_Surface		*invert_pixels(SDL_Surface *s)
{
	unsigned char	*pix_src;
	unsigned char	*pix_inv;
	SDL_Surface		*result;
	int				i;
	int				j;

	result = copy_sdl_surface(s);
	pix_src = (unsigned char*)s->pixels;
	pix_inv = (unsigned char*)result->pixels;
	i = 0;
	while (i < s->h)
	{
		j = 0;
		while (j < s->w * s->format->BytesPerPixel)
		{
			pix_inv[(s->w * s->format->BytesPerPixel * (s->h - 1 - i)) + j] =
				pix_src[(s->w * s->format->BytesPerPixel * i) + j];
			j++;
		}
		i++;
	}
	return (result);
}
