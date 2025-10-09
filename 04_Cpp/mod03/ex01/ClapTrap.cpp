/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 11:14:17 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 12:36:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

using std::cout;
using std::endl;

// OCF 

ClapTrap::ClapTrap(void)
{
	this->_attackDemage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	this->_name = "Default";
	cout << "ClapTrap constructor por defecto llamado y creado: "
		<< this->_name << "." << endl;
}

ClapTrap::ClapTrap(const std::string& name)
{
	this->_name = name;
	this->_attackDemage = 0;
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	cout << "ClapTrap constructo con parametros llamado y creado: " << this->_name << endl;
}

ClapTrap::ClapTrap(const ClapTrap& newClapTrap)
{
	cout << "ClapTrap constructor de copia llamado y copiado el ClapTrap: "
	<< newClapTrap.getName() << "." << endl;
	*this = newClapTrap;
}

ClapTrap::~ClapTrap()
{
	cout << "ClapTrap destructor llamado y destruido "
		<< this->getName() << "." << endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& newClapTrap)
{
	cout << "ClapTrap de asiganacion llamado y asignado: " << newClapTrap.getName() << endl;
	this->setName(newClapTrap.getName());
	this->setAttackDemage(newClapTrap.getAttackDemage());
	this->setEnergyPoints(newClapTrap.getEnergyPoints());
	this->setHitPoints(newClapTrap.getHitPoints());

	return *this;
}

// Getter

const std::string&	ClapTrap::getName(void) const
{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints(void) const
{
	return this->_hitPoints;
}

unsigned int	ClapTrap::getEnergyPoints(void) const
{
	return this->_energyPoints;
}

unsigned int	ClapTrap::getAttackDemage(void) const
{
	return this->_attackDemage;
}

// Setter

void	ClapTrap::setName(std::string name)
{
	this->_name = name;
}

void	ClapTrap::setHitPoints(unsigned int hitPoints)
{
	this->_hitPoints = hitPoints;
}

void	ClapTrap::setEnergyPoints(unsigned int energyPoints)
{
	this->_energyPoints = energyPoints;
}

void	ClapTrap::setAttackDemage(unsigned int attackDemage)
{
	this->_attackDemage = attackDemage;
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->_energyPoints < 2)
	{
		cout << "ClapTrap " << this->_name << " intenta atacar a " << target << " pero, no tiene energía suficiente." << endl;
		return;
	}
	else if (this->_hitPoints <= 0)
	{
		cout << "ClapTrap " << this->_name << " intenta atacar a " << target << " pero no tiene HitPoints... esta muerto." << endl;
		return;
	}
	else
	{
		cout << "ClapTrap " << this->_name << " ataca a " << target << " causando " << this->_attackDemage << " puntos de daños!" << endl;
		this->_energyPoints -= 2;
	}
}

void ClapTrap::takeDamage(unsigned int amount) {
	
	if (amount > this->_hitPoints)
	{
		cout << "ClapTrap " << this->_name << " recibe " << this->_hitPoints << " puntos de daños!" << endl;
		this->_hitPoints = 0;
	}
	else
	{
		cout << "ClapTrap " << this->_name << " recibe " << amount << " puntos de daños!" << endl;
		this->_hitPoints -= amount;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	
	this->_hitPoints += amount;
	cout << "ClapTrap " << this->_name << " es reparado en " << amount << " puntos!" << endl;
}
