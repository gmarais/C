/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 13:08:26 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/22 16:04:13 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *s1, const void *s2, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		if (*(unsigned char *)s2 == (unsigned char)c)
			return ((void *)((unsigned char *)s1 + 1));
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
		i++;
	}
	return (NULL);
}
