/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 09:20:19 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 09:20:23 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_stack	*ft_checker_stacknew(int value)
{
	t_stack	*new;

	new = 0;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
	{
		free(new);
		return (NULL);
	}
	new->value = value;
	new->next = NULL;
	return (new);
}
