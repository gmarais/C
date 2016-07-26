/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 16:03:10 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/28 12:35:11 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	k;

	j = ft_strlen(dst);
	k = 0;
	if (size <= j)
		return (size + ft_strlen(src));
	while (src[k] != '\0' && j + k < size - 1)
	{
		dst[j + k] = src[k];
		k++;
	}
	dst[j + k] = '\0';
	if (size < ft_strlen(src))
		return (ft_strlen(src) + j);
	return (j + ft_strlen(src));
}
