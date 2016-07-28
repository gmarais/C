/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math_tools.h"

void	scale_matrix(t_mat4 *m, float x, float y, float z)
{
	t_mat4 scale;
	t_mat4 mult_res;

	scale = g_identity_matrix;
	scale.val[0] = x;
	scale.val[5] = y;
	scale.val[10] = z;
	mult_res = multiply_matrices(&scale, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void	translate_matrix(t_mat4 *m, float x, float y, float z)
{
	t_mat4	translation;
	t_mat4	mult_res;

	translation = g_identity_matrix;
	translation.val[12] = x;
	translation.val[13] = y;
	translation.val[14] = z;
	mult_res = multiply_matrices(&translation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void	rotate_x(t_mat4 *m, float angle)
{
	t_mat4	rotation;
	t_mat4	mult_res;
	float	sine;
	float	cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = g_identity_matrix;
	rotation.val[5] = cosine;
	rotation.val[6] = -sine;
	rotation.val[9] = sine;
	rotation.val[10] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void	rotate_y(t_mat4 *m, float angle)
{
	t_mat4	rotation;
	t_mat4	mult_res;
	float	sine;
	float	cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = g_identity_matrix;
	rotation.val[0] = cosine;
	rotation.val[2] = -sine;
	rotation.val[8] = sine;
	rotation.val[10] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}

void	rotate_z(t_mat4 *m, float angle)
{
	t_mat4	rotation;
	t_mat4	mult_res;
	float	sine;
	float	cosine;

	sine = (float)sin(angle);
	cosine = (float)cos(angle);
	rotation = g_identity_matrix;
	rotation.val[0] = cosine;
	rotation.val[1] = -sine;
	rotation.val[4] = sine;
	rotation.val[5] = cosine;
	mult_res = multiply_matrices(&rotation, m);
	ft_memcpy(m->val, mult_res.val, sizeof(m->val));
}
