#include "libft.h"
#include <stdlib.h>

int get_next_words(char ***words, int fd)
{
	char *line;

	if (get_next_line(fd, &line) <= 0)
	{
		*words = 0;
		return 0;
	}
	*words = ft_strsplit(line, ' ');
	free(line);
	return ft_strtablen(*words);
}

void clean_words_tab(char **words, int words_len)
{
	int i;

	i = 0;
	while (i < words_len)
	{
		free(words[i]);
		i++;
	}
}

