/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:23:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/30 15:13:45 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	std::cout << "Arma <" << _type << "> ha sido forjada." << std::endl;
}

Weapon::~Weapon(void)
{
	std:: cout << "Arma <"<< _type << "> ha sido destruida." << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (this->_type);
}

void Weapon::setType(std::string type)
{
	this->_type = type;
	std::cout << "Weapon ha cambiado de tipo a <" << this->_type << ">." << std::endl;
}