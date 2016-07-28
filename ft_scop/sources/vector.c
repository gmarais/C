/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "math_tools.h"

void	cross_product(float (*result)[3], const float a[3], const float b[3])
{
	(*result)[0] = a[1] * b[2] - a[2] * b[1];
	(*result)[1] = a[2] * b[0] - a[0] * b[2];
	(*result)[2] = a[0] * b[1] - a[1] * b[0];
}

float	dot_product(const float a[3], const float b[3])
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

void	normalize(float (*v)[3])
{
	float sum;

	sum = ft_absf((*v)[0]) + ft_absf((*v)[1]) + ft_absf((*v)[2]);
	(*v)[0] = (*v)[0] / sum;
	(*v)[1] = (*v)[1] / sum;
	(*v)[2] = (*v)[2] / sum;
}

void	copy_vector(float (*copy)[3], const float v[3])
{
	(*copy)[0] = v[0];
	(*copy)[1] = v[1];
	(*copy)[2] = v[2];
}
