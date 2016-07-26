/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 17:11:27 by gmarais           #+#    #+#             */
/*   Updated: 2013/12/01 15:38:01 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*res;

	res = ft_lstnew((lst)->content, (lst)->content_size);
	res = f(res);
	lst = lst->next;
	while (lst)
	{
		tmp = ft_lstnew((lst)->content, (lst)->content_size);
		tmp = f(tmp);
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
