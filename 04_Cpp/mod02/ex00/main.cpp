/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:49:19 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/03 12:08:23 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

int main() {
	Fixed i;
	Fixed j(i);
	Fixed k;

	k = j;

	std::cout << i.getRawBits() << std::endl;
	std::cout << j.getRawBits() << std::endl;
	std::cout << k.getRawBits() << std::endl;

	return 0;
}