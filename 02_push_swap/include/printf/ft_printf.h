/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 08:28:55 by jumarque          #+#    #+#             */
/*   Updated: 2024/10/21 13:26:15 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define TYPE_FORMAT "cspdiuxX%"

int		ft_printf(const char *str, ...);
int		ft_printdiu(unsigned char c, va_list args);
int		ft_prints(va_list args);
int		ft_printc(unsigned char c, va_list args);
int		ft_printhex(unsigned char c, va_list args);
int		ft_printptr(va_list args);
char	*ft_uitoa(unsigned int n);

#endif
