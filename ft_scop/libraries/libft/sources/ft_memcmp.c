/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:19:52 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/01 14:18:26 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i] && i < n - 1)
	{
		i++;
	}
	if (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i] != 0)
		return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
	return (0);
}
