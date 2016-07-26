/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:17:15 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/22 17:41:18 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;
	size_t	size;

	i = 0;
	size = ft_strlen(s2);
	if (size == 0)
		return ((char *)s1);
	while (s1[i])
	{
		if (ft_strncmp((char *)&s1[i], s2, size) == 0)
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
