/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURE_H
# define TEXTURE_H
# include "sdl_tools.h"

typedef struct		s_texture
{
	char			*img_src;
	unsigned char	*raw;
	unsigned int	width;
	unsigned int	height;
	unsigned int	bpp;
	unsigned int	compression;
	unsigned int	size;
	SDL_Surface		*surface;
	GLuint			id_texture;
}					t_texture;

t_texture			*new_texture(char *image_source);
void				delete_texture(t_texture *texture);
SDL_Surface			*load_bmp(t_texture *texture);
int					load_texture(t_texture *texture);

#endif
