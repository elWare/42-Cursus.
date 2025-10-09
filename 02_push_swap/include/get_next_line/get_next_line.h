/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:15:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/01/30 15:13:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

size_t	ft_len(char *str);
char	*ft_gnlstrchr(char *str, int c);
char	*ft_gnlstrjoin(char *s1, char *s2);
char	*ft_alloc(int fd, char *str);
char	*ft_nline(char *str);
char	*ft_rline(char *line);
char	*get_next_line(int fd);
#endif