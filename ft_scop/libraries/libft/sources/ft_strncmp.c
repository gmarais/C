/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:07:36 by gmarais           #+#    #+#             */
/*   Updated: 2014/02/25 10:49:29 by jpontat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ret;

	if (n == 0)
		return (0);
	i = 0;
	n--;
	while (s1[i] && s2[i] && s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	ret = (int)(s1[i] - s2[i]);
	ret = (ret < 0) ? -1 : ret;
	ret = (ret > 0) ? 1 : ret;
	return (ret);
}
