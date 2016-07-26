/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_get_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 17:03:37 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/21 17:10:43 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft.h"

static char *realloc_content(char *content, ssize_t cont_length, ssize_t ret)
{
	ssize_t old_size;
	ssize_t new_size;
	old_size = cont_length * sizeof(char);
	new_size = old_size + ret * sizeof(char);
	content = (char *)ft_realloc(content, old_size, new_size);
	return content;
}

static void copybuf(char *content, char *buf, ssize_t *cont_length, ssize_t ret)
{
	ssize_t		i;

	i = 0;
	while (i < ret)
	{
		content[*cont_length + i] = buf[i];
		i++;
	}
	*cont_length += ret;
	content[*cont_length] = 0;
}

char	*file_get_content(const char *path)
{
	char		*content;
	ssize_t		cont_length;
	char		buf[BUFF_SIZE + 1];
	ssize_t		ret;
	int			fd;

	if ((fd = open(path, O_RDONLY)) <= 0)
		return NULL;
	content = NULL;
	cont_length = 0;
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		content = realloc_content(content, cont_length, ret);
		if (content == NULL)
			break;
		copybuf(content, buf, &cont_length, ret);
	}
	close(fd);
	return content;
}