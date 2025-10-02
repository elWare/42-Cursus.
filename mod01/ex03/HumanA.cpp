/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 11:22:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/30 15:10:36 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon) : _name(name), _weapon(weapon)
{
	std::cout << "HumanA <"<< this->_name
				<< "> ha sido creado y empuñará el arma."<< std::endl; 
}

HumanA::~HumanA(void)
{
	std::cout << "HumanA <" << this->_name << "> ha sido destruido." << std::endl;
}

void HumanA::attack(void)
{
	std::cout << this->_name << " ataca con su arma " << this->_weapon.getType()
	<< "." << std::endl;
}