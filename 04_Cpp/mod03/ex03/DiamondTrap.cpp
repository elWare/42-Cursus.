/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 13:29:29 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/26 20:45:19 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), FragTrap(), ScavTrap()
{
	std::cout << "DiamondTrapo constructor por defecto llamado." << std::endl;
	
	this->_name = "Diamond_Default";
	this-> _attackDemage = 30;
	this-> _energyPoints = 50;
	this-> _hitPoints = 100;
}

DiamondTrap::DiamondTrap(const std::string& name)
	: ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), _name(name)
{
	std::cout << "DiamondTrap " << name << " ha sido creado." << std::endl;
	this-> _attackDemage = 30;
	this-> _energyPoints = 50;
	this-> _hitPoints = 100;
}

DiamondTrap::DiamondTrap(const DiamondTrap& newDiamondTrap) 
	: ClapTrap(newDiamondTrap), FragTrap(newDiamondTrap), ScavTrap(newDiamondTrap)
{
	std::cout << "DiamondTrap copy constructor called." << std::endl;
	this-> _name = newDiamondTrap._name;
	this-> _attackDemage = FragTrap::getAttackDemage();
	this-> _energyPoints = FragTrap::getEnergyPoints();
	this-> _hitPoints = FragTrap::getHitPoints();
}

void DiamondTrap::whoAmI(void) const
{
	std::cout << "DiamondTrap " << this-> _name << " es tambien conocido como " << ClapTrap::getName() << std::endl;
}

DiamondTrap::~DiamondTrap(){
    std::cout << "DiamondTrap " << this-> _name << " ha sido destruido. 💥" << std::endl;
}