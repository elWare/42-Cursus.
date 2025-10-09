/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 11:15:42 by jumarque          #+#    #+#             */
/*   Updated: 2024/11/28 08:27:46 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_create(int fd, char *buffer)
{
	char	*tmp_buff;
	ssize_t	fr;

	tmp_buff = malloc((BUFFER_SIZE + 1) * sizeof (char));
	if (!tmp_buff)
		return (NULL);
	fr = 1;
	while (!(ft_strchr(buffer, '\n')) && fr > 0)
	{
		fr = read(fd, tmp_buff, BUFFER_SIZE);
		if (fr == -1)
		{
			free(tmp_buff);
			free(buffer);
			return (NULL);
		}
		tmp_buff[fr] = '\0';
		buffer = ft_strjoin(buffer, tmp_buff);
	}
	free(tmp_buff);
	tmp_buff = NULL;
	return (buffer);
}

char	*ft_getline(char *buffer)
{
	char	*line;
	int		index;

	index = 0;
	if (buffer[index] == 0)
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	index += (buffer[index] == '\n');
	line = malloc((index + 1) * sizeof(char));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
	{
		line[index] = '\n';
		index++;
	}
	line[index] = '\0';
	return (line);
}

char	*ft_cleanline(char *buffer)
{
	char	*result_buffer;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	result_buffer = malloc((ft_strln(buffer) - i + 1) * sizeof(char));
	if (!result_buffer)
		return (NULL);
	i++;
	j = 0;
	while (buffer[i])
		result_buffer[j++] = buffer[i++];
	result_buffer[j] = '\0';
	free(buffer);
	buffer = NULL;
	return (result_buffer);
}

size_t	ft_strln(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
	{
		if (!buffer)
			free(buffer);
		line = NULL;
		return (NULL);
	}
	buffer = ft_create(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_getline(buffer);
	buffer = ft_cleanline(buffer);
	return (line);
}

