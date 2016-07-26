/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:57:37 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/21 18:44:33 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_sin(double radian)
{
	double sine;

	if (radian < -3.14159265)
		radian += 6.28318531;
	else if (radian > 3.14159265)
		radian -= 6.28318531;
	if (radian < 0)
		sine = radian * (1.27323954 + 0.405284735 * radian);
	else
		sine = radian * (1.27323954 - 0.405284735 * radian);
	if (sine < 0)
		sine = sine * (-0.225 * (sine + 1) + 1);
	else
		sine = sine * (0.225 * (sine - 1) + 1);
	return (sine);
}

double		ft_sin_d(double degree)
{
	double sine;
	double radian;

	radian = 3.14159265 * degree / 180.0;
	if (radian < -3.14159265)
		radian += 6.28318531;
	else if (radian > 3.14159265)
		radian -= 6.28318531;
	if (radian < 0)
		sine = radian * (1.27323954 + 0.405284735 * radian);
	else
		sine = radian * (1.27323954 - 0.405284735 * radian);
	if (sine < 0)
		sine = sine * (-0.225 * (sine + 1) + 1);
	else
		sine = sine * (0.225 * (sine - 1) + 1);
	return (sine);
}
