/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 16:56:38 by gmarais           #+#    #+#             */
/*   Updated: 2014/01/18 18:55:01 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_exp(int a, int ex)
{
	double	ret;

	if (ex == 0)
		return (1);
	if (ex > 0)
	{
		ret = (double)a;
		while (--ex)
			ret *= (double)a;
	}
	else
	{
		ret = 1.0;
		while (ex++)
			ret /= (double)a;
	}
	return (ret);
}
