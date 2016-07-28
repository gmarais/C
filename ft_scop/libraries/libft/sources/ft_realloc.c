/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 13:07:14 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/27 13:19:47 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *s, size_t old_size, size_t new_size)
{
	void	*copy;

	copy = NULL;
	if (new_size > 0)
	{
		copy = malloc(new_size);
		if (copy != NULL && s != NULL && old_size <= new_size)
		{
			copy = ft_memcpy(copy, s, old_size);
			free(s);
		}
	}
	return (copy);
}
