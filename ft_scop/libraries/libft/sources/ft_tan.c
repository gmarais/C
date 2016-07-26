/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tan.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 18:53:46 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/18 18:56:11 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_tan_d(double degree)
{
	if (ft_cos_d(degree) != 0)
		return (ft_sin_d(degree) / ft_cos_d(degree));
	else
		return (ft_sin_d(degree) / 0.0000001);
}

double	ft_tan(double radian)
{
	if (ft_cos(radian) != 0)
		return (ft_sin(radian) / ft_cos(radian));
	else
		return (ft_sin(radian) / 0.0000001);
}
