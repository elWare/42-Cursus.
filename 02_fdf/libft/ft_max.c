/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 14:06:29 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/21 10:00:49 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int *array, int len)
{
	int		i;
	int		max;

	i = 0;
	max = array[i];
	while (i < len)
	{
		if (array[i] > max)
			max = array[i];
		i++;
	}
	return (max);
}
