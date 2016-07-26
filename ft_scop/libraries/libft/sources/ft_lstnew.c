/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 15:41:25 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/27 12:31:44 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*tmp;
	void	*ct;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (content != NULL)
	{
		ct = malloc(content_size);
		ct = ft_memcpy(ct, content, content_size);
	}
	if (tmp)
	{
		tmp->content = (content == NULL) ? NULL : ct;
		tmp->content_size = (content == NULL) ? 0 : content_size;
		tmp->next = NULL;
	}
	return (tmp);
}
