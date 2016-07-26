/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 15:32:24 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/21 14:43:00 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *s1, const void *s2, size_t n)
{
	void	*ret;

	ret = s1;
	while (n)
	{
		*(unsigned char *)s1 = *(unsigned char *)s2;
		s1 = (unsigned char *)s1 + 1;
		s2 = (unsigned char *)s2 + 1;
		n--;
	}
	return (ret);
}
