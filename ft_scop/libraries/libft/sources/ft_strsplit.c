/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 18:50:10 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/29 18:46:08 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static char	*ft_subfunction(size_t i, size_t count, char const *s)
{
	char	*str;

	str = (char *)malloc(count + 1);
	str = ft_strncpy(str, (char *)&s[i - count], (size_t)(count));
	str[count] = '\0';
	return (str);
}

static char	**ft_alloc(size_t len, size_t *lct)
{
	char	**ret;

	if (len != 0)
		return ((char **)malloc(len * sizeof(char *)));
	ret = (char **)malloc(sizeof(char *));
	ret[0] = NULL;
	*lct = *lct + 1;
	return (ret);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	count;
	size_t	lct;

	i = 0;
	lct = 0;
	count = 0;
	tab = ft_alloc(ft_strlen(s), &lct);
	while (s[i] != '\0')
	{
		if (s[i] != c && s[i] != '\0')
			count++;
		else if (count > 0)
		{
			tab[lct++] = ft_subfunction(i, count, s);
			count = 0;
		}
		i++;
	}
	if (count > 0)
		tab[lct++] = ft_subfunction(i, count, s);
	tab[lct] = NULL;
	return (tab);
}
