/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 15:03:33 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 13:38:02 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;

	ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ret = ft_strcpy(ret, s1);
	return (ft_strcat(ret, s2));
}
