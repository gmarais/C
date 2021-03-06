/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookat_projection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math_tools.h"

static void	look_at_result_line(t_mat4 *r
	, int *i
	, const float eye[3]
	, float v[3])
{
	r->val[(*i)] = v[0];
	r->val[(*i) + 4] = v[1];
	r->val[(*i) + 8] = v[2];
	(*i)++;
}

t_mat4		look_at(const float eye[3]
	, const float center[3]
	, const float up[3])
{
	t_mat4	result;
	float	z[3];
	float	y[3];
	float	x[3];
	int		i;

	z[0] = eye[0] - center[0];
	z[1] = eye[1] - center[1];
	z[2] = eye[2] - center[2];
	normalize(&z);
	copy_vector(&y, up);
	cross_product(&x, y, z);
	normalize(&x);
	cross_product(&y, z, x);
	normalize(&y);
	i = 0;
	result = g_identity_matrix;
	look_at_result_line(&result, &i, eye, x);
	look_at_result_line(&result, &i, eye, y);
	look_at_result_line(&result, &i, eye, z);
	result.val[12] = -dot_product(x, eye);
	result.val[13] = -dot_product(y, eye);
	result.val[14] = -dot_product(z, eye);
	return (result);
}

t_mat4		create_proj_matrix(float fov, float ratio, float near, float far)
{
	t_mat4		out;
	const float	y_scale = cotangent(degrees_to_radians(fov / 2.0f));
	const float	x_scale = y_scale / ratio;
	const float	frustum_length = far - near;

	ft_bzero(out.val, sizeof(float[16]));
	out.val[0] = x_scale;
	out.val[5] = y_scale;
	out.val[10] = -(far + near) / frustum_length;
	out.val[11] = -1;
	out.val[14] = -((2.0 * near * far) / frustum_length);
	return (out);
}
