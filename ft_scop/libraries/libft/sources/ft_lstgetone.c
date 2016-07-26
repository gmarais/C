/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:03:24 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/27 18:24:26 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstgetone(t_list *beginlst, int index)
{
	int i = 0;

	if (i > index)
		return NULL;
	while (i < index && beginlst)
	{
		beginlst = beginlst->next;
		i++;
	}
	return beginlst;
}
