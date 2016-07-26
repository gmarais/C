/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:27:47 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/01 14:19:54 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	unsigned char	*c;
	int				overlap;

	overlap = 0;
	c = (unsigned char *)s2;
	while (c < (unsigned char *)s2 + n)
	{
		if (c == (unsigned char*)s1)
			overlap = 1;
		c++;
	}
	if (overlap)
	{
		c = (unsigned char *)s2 + n - 1;
		while (c >= (unsigned char *)s2)
		{
			*(c + (s1 - s2)) = *c;
			c--;
		}
		return (s1);
	}
	return (ft_memcpy(s1, s2, n));
}
