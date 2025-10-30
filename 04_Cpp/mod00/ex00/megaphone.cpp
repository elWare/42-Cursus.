/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 17:16:21 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/30 18:23:10 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

std::string trim(const std::string& str) {

	size_t	first;
	size_t	last;
	
	first = str.find_first_not_of(" \t\n\r\f\v"); // Busca cualquier tipo de espacio
	if (std::string::npos == first) {
		return "";
	}
	last = str.find_last_not_of(" \t\n\r\f\v");
	return str.substr(first, (last - first + 1));
}

int	main(int argc, char *argv[])
{
	std::string	str;
	size_t	i;
	size_t	j;
	
	if (argc == 1)
		std::cout <<  "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		i = 1;
		while (i < (size_t)argc)
		{
			j = 0;
			str = trim(argv[i]);
			while (j < (size_t)str.length())
			{
				std::cout << static_cast<char>(toupper(str[j]));
				j++;
			}
			i++;
			if (i != (size_t)argc)
				std::cout << static_cast<char>(32);
		}
		std::cout << std::endl;
	}
	return 0;
}