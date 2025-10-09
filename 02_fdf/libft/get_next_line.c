/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/13 16:04:03 by qmuntada          #+#    #+#             */
/*   Updated: 2025/03/22 10:05:03 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../include/fdf.h"

int	ft_line_verif(char **line, char **tmp, int res, char **buff)
{
	int	len;

	len = (int)ft_strlen(*tmp);
	if (res == 0 && len > 0)
	{
		*line = *tmp;
		ft_free(buff, tmp);
		return (1);
	}
	if (res == 0 && len == 0)
	{
		ft_free(buff, tmp);
		return (0);
	}
	ft_free(buff, tmp);
	return (res);
}

char	*ft_read_line(char *tmp)
{
	size_t			size;
	char			*line;

	size = 0;
	while (tmp[size] != '\n')
		size++;
	line = (char *)malloc((size + 1) * sizeof(char));
	line = ft_strncpy(line, tmp, size);
	line[size] = '\0';
	return (line);
}

char	*ft_cpycat(char *s1, char *s2)
{
	char	*tmp;

	tmp = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s2)
		return (s1);
	if (!s1)
		return (s2);
	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2));
	tmp = ft_strcpy(tmp, s1);
	tmp = ft_strncat(tmp, s2, ft_strlen(s2));
	free(s1);
	return (tmp);
}

int	ft_gnl(int const fd, char **line)
{
	static char				*str;
	int						res;
	char					*buf;
	char					*tmp;

	if (fd < 0 || !line || BUFF_SIZE < 1 || BUFF_SIZE > 10000000)
		return (-1);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (str == NULL)
		str = ft_strnew(BUFF_SIZE);
	tmp = malloc(sizeof(char) * BUFF_SIZE);
	tmp = ft_strncpy(tmp, str, BUFF_SIZE);
	while (!(ft_strchr(tmp, '\n')))
	{
		res = read(fd, buf, BUFF_SIZE);
		if (res < 1)
			return (ft_line_verif(line, &tmp, res, &buf));
		buf[res] = '\0';
		tmp = ft_cpycat(tmp, buf);
	}
	*line = ft_read_line(tmp);
	if (ft_strchr(tmp, '\n'))
		str = ft_strncpy(str, ft_strchr(tmp, '\n') + 1, BUFF_SIZE);
	ft_free(&buf, &tmp);
	return (1);
}
