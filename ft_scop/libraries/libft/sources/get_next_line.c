/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 18:24:37 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/15 06:35:48 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static void	ft_ifbufin(char *buf, size_t i, char **line, char **result)
{
	if (buf[i] == '\n' || buf[i] == '\0')
	{
		ft_strcpy(buf, (char *)&buf[i + 1]);
		buf[ft_strlen(buf) + 1] = '\0';
	}
	*line = *result;
}

static int	ft_copybuf(char **result, char *buf, size_t *i, size_t *j)
{
	size_t s;
	*i = 0;
	int char_size = sizeof(char);

	while (buf[*i] != '\n' && buf[*i] != '\0' && *i < BUFF_SIZE)
	{
		s = ft_strlen(*result) + 1;
		*result = ft_realloc(*result, s * char_size, (s + *j) * char_size);
		if (!(*result))
			return (-1);
		(*result)[*j] = buf[*i];
		(*i)++;
		(*j)++;
	}
	(*result)[*j] = '\0';
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	char		*result;
	static char	buf[BUFF_SIZE + 1];
	size_t		i;
	size_t		j;
	ssize_t		ret;

	j = 0;
	result = (char *)malloc(2);
	if (ft_copybuf(&result, buf, &i, &j))
		return (-1);
	ret = ft_strlen(buf) - j;
	while ((buf[i] != '\n') && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0 || ft_copybuf(&result, buf, &i, &j) || (buf[ret] = '\0'))
			return (-1);
		i = (i == BUFF_SIZE) ? 0 : i;
	}
	ft_ifbufin(buf, i, line, & result);
	if (ret == 0 && ft_strlen(buf) > 0)
		buf[0] = '\0';
	if ((ret > 0 && ret <= BUFF_SIZE) || (ret == 0 && ft_strlen(result) > 0))
		return (1);
	return (0);
}
