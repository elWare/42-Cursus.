/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:12:22 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 12:31:15 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << "FragTrap constructor por defecto llamado." << std::endl;

	this->_attackDemage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
}

FragTrap::FragTrap(const std::string& name) : ClapTrap(name)
{
	std::cout << "FragTrap " << name << " ha sido creado." << std::endl;
	this->_attackDemage = 30;
	this->_energyPoints = 100;
	this->_hitPoints = 100;
}

FragTrap::FragTrap(const FragTrap& newFragTrap) : ClapTrap(newFragTrap)
{
	std::cout << "FragTrap constructor de copias llamado.";
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor ha sido llamado para " << this->getName() << "." << std::endl;
}

void FragTrap::highFivesGuys(void) const
{
	std::cout << "FragTrap " << this->_name << " dice: Give me five!" << std::endl;
}