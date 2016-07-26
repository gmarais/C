/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 12:24:28 by gmarais           #+#    #+#             */
/*   Updated: 2014/03/23 18:29:59 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static double	ten_pow(int pow)
{
	double		ret;

	ret = 1.0;
	if (pow < 0)
	{
		while (pow)
		{
			ret *= 0.1;
			pow++;
		}
		return (ret);
	}
	while (pow)
	{
		ret *= 10;
		pow--;
	}
	return (ret);
}

static void		eflag(char **s, int *e)
{
	int		e_sign;
	int		e_bis;

	if ((**s == '-' && (*s)++) || (**s == '+' && (*s)++ && !42))
		e_sign = -1;
	else
		e_sign = 1;
	e_bis = 0;
	while (**s && ft_isdigit(**s))
	{
		e_bis = 10 * e_bis + **s - '0';
		(*s)++;
	}
	*e += e_bis * e_sign;
}

static void		add_to_result(char **str, int *j, double *result)
{
	if (*j > -308)
		*result += ten_pow(*j) * (**str - '0');
	(*j)--;
	(*str)++;
}

static double	ret_result(double result, int e)
{
	if (e < -308)
		return (0.0);
	else if (e < 308 || (e == 308 && result < 1.70141183460469228))
		result *= ten_pow(e);
	else
		result = 1.0 / 0.0;
	return (result);
}

double			ft_atof(char *str)
{
	double	result;
	int		j;
	int		sign;
	int		e;

	result = 0.0;
	e = -1;
	j = 0;
	while (*str && (*str == ' ' || (*str >= 9 && *str <= 13)))
		str++;
	sign = ((*str == '-' && str++) || (*str == '+' && str++ && !42)) ? -1 : 1;
	while (*str && ft_isdigit(*str))
	{
		add_to_result(&str, &j, &result);
		e++;
	}
	if (*str == '.')
		str++;
	while (*str && ft_isdigit(*str))
		add_to_result(&str, &j, &result);
	if ((*str == 'e' || *str == 'E' || *str == 'd' || *str == 'D') && str++)
		eflag(&str, &e);
	return (ret_result(result, e) * sign);
}
