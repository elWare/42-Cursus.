/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 09:33:37 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 11:38:23 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int n, std::string name)
{
	if (n <= 0 && n < 1000)
	{
		std::cout << "Error: El número de zombis para la horda debe ser positivo y menor de 1000."
				<< std::endl;
		return NULL;
	}
	
	Zombie* horde;
	
	horde = new Zombie[n];
	for (int i = 0; i < n; i++)
	{
		std::stringstream ss;
		ss << name << "_" << i;
		horde[i].setName(ss.str());
	}
	return horde;
}