/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:03:37 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/21 17:10:43 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

static int		ft_line_len(char *str, int max)
{
	int		i;

	i = 0;
	while (i < max && str[i] != '\n')
		i++;
	return (i);
}

static int		copybuf(int *ret, char *buf, int *plen, char **line)
{
	int		len;
	int		bool;
	int		i;

	len = ft_line_len(buf, *ret);
	bool = (len < *ret) ? 1 : 0;
	*line = (char *)ft_realloc(*line, *plen, *plen + len + 1);
	i = -1;
	while (++i < len)
		(*line)[*plen + i] = buf[i];
	(*line)[*plen + i] = 0;
	*plen += len;
	*ret -= len + bool;
	ft_strncpy(buf, buf + len + 1, *ret);
	if (bool)
		return (*plen + 1);
	return (-1);
}

int				ft_getline(char **line, int const fd)
{
	static int	ret = 0;
	static char	buf[BUFF_SIZE + 1];
	int			plen;
	int			check;

	*line = NULL;
	plen = 0;
	while (1)
	{
		if (ret)
		{
			if ((check = copybuf(&ret, buf, &plen, line)) != -1)
				return (check);
		}
		else
		{
			if ((ret = read(fd, buf, BUFF_SIZE)) < 0)
				return (-1);
			if (ret == 0)
				return (plen);
			buf[ret] = 0;
		}
	}
}
