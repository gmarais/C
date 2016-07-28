/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "time_tools.h"

double	update_delta_time(void)
{
	static double	last_time = 0;
	double			current_time;
	double			delta_time;

	current_time = CURRENT_TIME;
	delta_time = current_time - last_time;
	last_time = current_time;
	return (delta_time);
}

float	custom_rand(void)
{
	static unsigned int	x;
	unsigned int		number;
	const unsigned int	range = 11969;
	const unsigned int	primary_factor_a = 44273;
	const unsigned int	primary_factor_b = 32099;

	number = (primary_factor_a * (clock() + x) + x * primary_factor_b);
	number %= range + 1;
	x++;
	return ((float)number / (float)range);
}
