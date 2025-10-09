/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 10:56:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/04/08 12:59:26 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_list	*ft_getlstfile(int fd, int *len)
{
	char	**line;
	t_list	*list;

	line = malloc(sizeof(char **) * 1);
	if (line == NULL)
		exit (0);
	list = NULL;
	while (ft_gnl(fd, line) == 1)
	{
		*len = ft_strlen(*line);
		ft_lstpushback(&list, *line, *len);
		if (*line)
		{
			free(*line);
			*line = NULL;
		}
	}
	if (line)
		free (line);
	return (list);
}

int	ft_tablen(char **array)
{
	int	x;

	x = 0;
	while (*(array + x))
		x++;
	return (x);
}

int	*ft_putarray(t_smem *mem)
{
	int		i;
	int		y;
	int		*valueline;
	char	**line;

	i = -1;
	valueline = NULL;
	line = mem->line;
	y = ft_tablen(line);
	if (y < mem->len)
		mem->len = y;
	valueline = malloc(sizeof(int) * y);
	if (!valueline)
		ft_error(mem, 1);
	while (++i < y)
		valueline[i] = ft_atoi(line[i]);
	return (valueline);
}

void	ft_getarray(int fd, t_smem *mem)
{
	t_list	*ptr_lst;
	int		x;

	x = -1;
	mem->list = ft_getlstfile(fd, &mem->len);
	if (!mem->list)
		ft_error(mem, 0);
	ptr_lst = mem->list;
	mem->array = malloc(sizeof(int *) * ft_lstlen(mem->list));
	while (ptr_lst && mem->array)
	{
		mem->line = ft_strsplit(ptr_lst->content, ' ');
		mem->array[++x] = ft_putarray(mem);
		mem->line = ft_freeline(mem->line);
		ptr_lst = ptr_lst->next;
	}
	mem->wid = x + 1;
	ft_lstclear(&mem->list);
	mem->list = NULL;
	if (!mem->array)
		ft_error(mem, 0);
}

int	main(int argc, char **argv)
{
	int		fd;
	t_smem	mem;

	if (argc > 1)
	{
		ft_initsmem(&mem);
		fd = open(argv[1], O_RDONLY);
		if (fd < 0)
			return (0);
		ft_getarray(fd, &mem);
		close(fd);
		ft_getcolor(&mem);
		if (mem.array)
			ft_displaytab(&mem);
		return (0);
	}
	return (-1);
}
