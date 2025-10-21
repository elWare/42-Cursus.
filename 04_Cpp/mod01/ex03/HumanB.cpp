/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:46:44 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 12:21:04 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string nName) : name(nName), weapon(NULL)
{
		std::cout << "HumanB <"<< this->name
				<< "> ha sido creado." << std::endl;
}

HumanB::~HumanB(void)
{
	std::cout << "HumanB <" << this->name << "> ha sido destruido." << std::endl;
}

void HumanB::attack(void)
{
	if (this->weapon == NULL)
		std::cout << this->name << " intenta atacar pero no tiene arma." << std::endl;
	else
		std::cout << this->name << " ataca con su arma " << this->weapon->getType() 
				<< "." << std::endl;
}

void HumanB::setWeapon(Weapon& nWeapon)
{
	this->weapon = &nWeapon;
	std::cout << "HumanB <"<< this->name << "> ahora empuñará el arma <" << this->weapon->getType()
		<< ">." << std::endl;
}
