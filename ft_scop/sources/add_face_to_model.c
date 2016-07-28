/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_face_to_model.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "model.h"
#include "time_tools.h"

static void	add_zy_vt_to_vertex(t_vertex *vertex)
{
	float vt[2];

	vt[e_uv_u] = vertex->position[e_xyz_z] / MAX_OBJ_SCALE + MAX_OBJ_SCALE / 2;
	vt[e_uv_v] = vertex->position[e_xyz_y] / MAX_OBJ_SCALE + MAX_OBJ_SCALE / 2;
	ft_memcpy(&vertex->tex_coord, vt, sizeof(float [2]));
}

static void	set_random_color(float (*color)[4])
{
	(*color)[e_rgba_r] = custom_rand();
	(*color)[e_rgba_g] = custom_rand();
	(*color)[e_rgba_b] = custom_rand();
	(*color)[e_rgba_a] = 1;
}

void		add_face_to_model(t_obj obj, int obj_face[3][3], t_model *model)
{
	t_list		*tmp;
	int			i;
	t_vertex	vertex;
	float		random_color[SIZE_RGBA];

	i = -1;
	while (++i < 3)
	{
		if ((tmp = ft_lstgetone(obj.v, obj_face[i][0] - 1)))
			ft_memcpy(&vertex.position, tmp->content, sizeof(float [3]));
		if ((tmp = ft_lstgetone(obj.color, obj_face[i][0] - 1)))
			ft_memcpy(&vertex.color, tmp->content, sizeof(float [4]));
		else
		{
			set_random_color(&random_color);
			ft_memcpy(&vertex.color, random_color, sizeof(float [4]));
		}
		if ((tmp = ft_lstgetone(obj.vt, obj_face[i][1] - 1)))
			ft_memcpy(&vertex.tex_coord, tmp->content, sizeof(float [2]));
		else
			add_zy_vt_to_vertex(&vertex);
		tmp = ft_lstnew(&vertex, sizeof(t_vertex));
		ft_lstadd_back(&model->vertices, tmp);
		model->v_size++;
	}
}
