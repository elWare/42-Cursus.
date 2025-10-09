/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 12:51:55 by jumarque          #+#    #+#             */
/*   Updated: 2024/09/29 19:28:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*fwd_ptr;

	if (!lst)
		return (lst);
	else
	{
		fwd_ptr = lst->next;
		while (fwd_ptr)
		{
			lst = fwd_ptr;
			fwd_ptr = fwd_ptr->next;
		}
		return (lst);
	}
}
