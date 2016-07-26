#include "model.h"

static void add_float_tab_lst(t_list **lst, char **words, int tab_size, int w_len)
{
	float	content[tab_size];
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < w_len - 1 && i < tab_size)
	{
		content[i] = ft_atof(words[i + 1]);
		i++;
	}
	tmp = ft_lstnew(content, sizeof(float[tab_size]));
	ft_lstadd_back(lst, tmp);
}

static void get_obj_vertex_indexes(char *word, int vertex[3])
{
	char **indexes;

	indexes = ft_strsplit(word, '/');
	if (ft_strtablen(indexes) == 3)
	{
		vertex[0] = ft_atoi(indexes[0]);
		vertex[1] = ft_atoi(indexes[1]);
		vertex[2] = ft_atoi(indexes[2]);
	}
	else if (ft_strtablen(indexes) >= 1)
	{
		vertex[0] = ft_atoi(indexes[0]);
		vertex[1] = 0;
		vertex[2] = 0;
	}
}

static void add_face_tab_lst(t_list **lst, char **words, int words_len)
{
	int		face[3][3];
	t_list	*tmp;

	get_obj_vertex_indexes(words[1], face[0]);
	get_obj_vertex_indexes(words[2], face[1]);
	get_obj_vertex_indexes(words[3], face[2]);
	tmp = ft_lstnew(face, sizeof(int[3][3]));
	ft_lstadd_back(lst, tmp);
	if (words_len > 4)
	{
		get_obj_vertex_indexes(words[4], face[1]);
		tmp = ft_lstnew(face, sizeof(int[3][3]));
		ft_lstadd_back(lst, tmp);
	}
}

t_obj load_obj(int fd)
{
	t_obj obj;
	char **words;
	int words_len;

	obj.v = 0;
	obj.color = 0;
	obj.vn = 0;
	obj.vt = 0;
	obj.f = 0;
	while ((words_len = get_next_words(&words, fd)) > 0)
	{
		if (words_len >= 4 && ft_strcmp(words[0], "v") == 0)
			add_float_tab_lst(&obj.v, words, 3, words_len);
		if (words_len >= 4 && ft_strcmp(words[0], "color") == 0)
			add_float_tab_lst(&obj.color, words, 4, words_len);
		if (words_len >= 4 && ft_strcmp(words[0], "vn") == 0)
			add_float_tab_lst(&obj.vn, words, 3, words_len);
		if (words_len >= 3 && ft_strcmp(words[0], "vt") == 0)
			add_float_tab_lst(&obj.vt, words, 2, words_len);
		if (words_len >= 4 && ft_strcmp(words[0], "f") == 0)
			add_face_tab_lst(&obj.f, words, words_len);
		clean_words_tab(words, words_len);
	}
	return obj;
}
