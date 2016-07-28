/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math_tools.h"

const double	g_pi = 3.14159265358979323846;
const t_mat4	g_identity_matrix = {{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1}};

float			cotangent(float angle)
{
	return (float)(1.0 / tan(angle));
}

float			degrees_to_radians(float degrees)
{
	return (degrees * (float)(g_pi / 180.0));
}

float			radians_to_degrees(float radians)
{
	return (radians * (float)(180.0 / g_pi));
}

t_mat4			multiply_matrices(const t_mat4 *m1, const t_mat4 *m2)
{
	t_mat4			out;
	unsigned int	row;
	unsigned int	column;
	unsigned int	row_offset;

	out = g_identity_matrix;
	row = 0;
	row_offset = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			out.val[row_offset + column] =
				(m1->val[row_offset + 0] * m2->val[column + 0])
				+ (m1->val[row_offset + 1] * m2->val[column + 4])
				+ (m1->val[row_offset + 2] * m2->val[column + 8])
				+ (m1->val[row_offset + 3] * m2->val[column + 12]);
			column++;
		}
		row++;
		row_offset = row * 4;
	}
	return (out);
}
