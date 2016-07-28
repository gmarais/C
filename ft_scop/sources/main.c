/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"
#include "model.h"

t_env		g_env;
enum e_rfcg	rfc_mode;

static void	clean_quit(void)
{
	if (g_env.context != 0)
	{
		SDL_GL_DeleteContext(g_env.context);
		g_env.context = 0;
	}
	if (g_env.w != 0)
	{
		SDL_DestroyWindow(g_env.w);
		g_env.w = 0;
	}
	if (g_env.shader)
	{
		delete_shader(g_env.shader);
		free(g_env.shader);
		g_env.shader = NULL;
	}
	if (g_env.texture)
	{
		delete_texture(g_env.texture);
		free(g_env.texture);
		g_env.texture = NULL;
	}
	SDL_Quit();
}

static void	parse_arguments(int ac
	, char **av
	, char **obj_file
	, char **img_file)
{
	int i;

	i = 0;
	rfc_mode = e_rfcg_greyscale;
	*obj_file = BASE_OBJ;
	*img_file = BASE_IMG;
	while (++i < ac)
	{
		if (!ft_strcmp(av[i], "-c"))
			rfc_mode = e_rfcg_colors;
		else if (ft_strlen(av[i]) > 4)
		{
			if (!ft_strcmp((char *)(av[i] + ft_strlen(av[i]) - 4), ".obj"))
			{
				*obj_file = av[i];
			}
			if (!ft_strcmp((char *)(av[i] + ft_strlen(av[i]) - 4), ".bmp"))
				*img_file = av[i];
		}
	}
}

int			main(int ac, char **av)
{
	char	*obj_file;
	char	*img_file;

	parse_arguments(ac, av, &obj_file, &img_file);
	update_delta_time();
	if (create_window(obj_file, img_file) == 0)
		main_loop();
	clean_quit();
	return (0);
}
