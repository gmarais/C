/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:01:50 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/01 14:41:51 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	beg;
	size_t	end;
	char	*ret;

	if (ft_strlen(s) == 0)
		return (ft_strnew(0));
	beg = 0;
	while (s[beg] && (s[beg] == ' ' || (s[beg] >= 9 && s[beg] <= 13)))
		beg++;
	end = ft_strlen(s) - 1;
	while (end && (s[end] == ' ' || (s[end] >= 9 && s[end] <= 13)))
		end--;
	end++;
	if (end > beg)
	{
		ret = ft_strnew(end - beg);
		ret = ft_strncpy(ret, (char *)&s[beg], end - beg);
		ret[end - beg + 1] = '\0';
		return (ret);
	}
	return (ft_strnew(0));
}
