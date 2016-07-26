/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmarais <gmarais@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:03:24 by gmarais           #+#    #+#             */
/*   Updated: 2013/11/27 18:24:26 by gmarais          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (del != NULL)
		del((*alst)->content, (*alst)->content_size);
	else
		free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
