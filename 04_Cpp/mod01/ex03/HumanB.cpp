/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:46:44 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/30 15:17:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL)
{
		std::cout << "HumanB <"<< this->_name
				<< "> ha sido creado." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB <" << this->_name << "> ha sido destruido." << std::endl;
}

void HumanB::attack(void)
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " intenta atacar pero no tiene arma." << std::endl;
	else
		std::cout << this->_name << " ataca con su arma " << this->_weapon->getType() 
				<< "." << std::endl;
}

void HumanB::setWeapon(Weapon& weapon)
{
	this->_weapon = &weapon;
	std::cout << "HumanB <"<< this->_name << "> ahora empuñará el arma <" << this->_weapon->getType()
		<< ">." << std::endl;
}
