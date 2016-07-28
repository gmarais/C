/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_tools.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SDL_TOOLS_H
# define SDL_TOOLS_H

# include <SDL2/SDL.h>
# include <GL/glew.h>

SDL_Surface	*copy_sdl_surface(SDL_Surface *surface);
SDL_Surface	*invert_pixels(SDL_Surface *s);

#endif
