/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:22:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 12:23:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string nName, Weapon& nWeapon) : name(nName), weapon(nWeapon)
{
	std::cout << "HumanA <"<< this->name
				<< "> ha sido creado y empuñará el arma."<< std::endl; 
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA <" << this->name << "> ha sido destruido." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->name << " ataca con su arma " << this->weapon.getType()
	<< "." << std::endl;
}