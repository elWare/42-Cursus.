/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 17:45:55 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/06 18:01:07 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

using std::cout;
using std::endl;

ScavTrap::ScavTrap() : ClapTrap()
{
	cout << "Scavtrap constructor por defecto llamado." << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDemage = 20;
}

ScavTrap::ScavTrap(const std::string name) : ClapTrap(name)
{
	cout << "Scavtrap constructor " << name << " ha sido llamado." << endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDemage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& newScavTrap) : ClapTrap(newScavTrap)
{
	cout << "ScavTrap constructor de copia llamado." << endl;
}

ScavTrap::~ScavTrap()
{
	cout << "ScavTrap " << this->getName() << " ha sido destruido." << endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 5)
	{
		cout << "ScavTrap " << this->getName() << " no tiene suficientes puntos de energía para atacar." << endl;
		return ;
	}
	else if (this->_hitPoints <= 0)
	{
		cout << "ScavTrap " << this->getName() << " no puede atacar, está sin puntos de vida." << endl;
		return;
	}
	{
		this->_energyPoints -= 5;
		cout << "ScavTrap " << this->getName() << " ataca a " << target << ","; 
		cout << " causando: " << this->_attackDemage << " puntos de daños!" << endl;
		cout << "\n\tAhora " << this->getName() << " tiene " << this->_energyPoints << " puntos de energía restantes." << endl;
	}
}

void ScavTrap::guardGate() const
{
	cout << "ScavTrap " << this->getName() << " ha entrado en Modo Guardián de la Puerta." << endl;
}