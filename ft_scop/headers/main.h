/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <GL/glew.h>
# include <SDL2/SDL.h>
# include <libft.h>
# include <stdlib.h>
# include "math_tools.h"
# include "shader.h"
# include "texture.h"
# include "time_tools.h"
# include "model.h"

# define WIN_WIDTH 1024
# define WIN_HEIGHT 640

typedef struct		s_env
{
	SDL_Window		*w;
	SDL_GLContext	*context;
	t_mat4			proj;
	t_mat4			mv;
	t_shader		*shader;
	t_texture		*texture;
	t_model			*mdl;
	short int		rots[3];
	short int		trans[3];
	float			col_to_text;
	short int		text_is_on;
}					t_env;

extern t_env		g_env;

void				draw();
void				main_loop();
int					create_window(char *obj_file, char *img_file);

#endif
