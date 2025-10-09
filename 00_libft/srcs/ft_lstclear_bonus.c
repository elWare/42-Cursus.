/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 18:56:57 by fmunoz-g          #+#    #+#             */
/*   Updated: 2025/02/24 08:45:40 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*deleted;

	if (*lst == NULL || del == NULL)
		return ;
	while (*lst != NULL)
	{
		deleted = *lst;
		*lst = deleted->next;
		del(deleted->content);
		free(deleted);
	}
	*lst = NULL;
}
