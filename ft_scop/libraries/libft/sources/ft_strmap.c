/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:41:36 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/22 15:17:13 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ret;
	size_t	i;

	i = 0;
	ret = ft_strdup(s);
	while (ret[i])
	{
		ret[i] = f(ret[i]);
		i++;
	}
	return (ret);
}
