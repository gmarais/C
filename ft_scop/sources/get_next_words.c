/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 17:52:23 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/25 21:08:25 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		get_next_words(char ***words, int fd)
{
	char	*line;

	if (get_next_line(fd, &line) <= 0)
	{
		*words = 0;
		return (0);
	}
	*words = ft_strsplit(line, ' ');
	free(line);
	return (ft_strtablen(*words));
}

void	clean_words_tab(char **words, int words_len)
{
	int		i;

	i = 0;
	while (i < words_len)
	{
		free(words[i]);
		i++;
	}
}
