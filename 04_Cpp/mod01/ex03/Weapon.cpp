/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 18:23:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 12:18:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string nType) : type(nType)
{
	std::cout << "Arma <" << this->type << "> ha sido forjada." << std::endl;
}

Weapon::~Weapon(void)
{
	std:: cout << "Arma <"<< type << "> ha sido destruida." << std::endl;
}

const std::string& Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
	std::cout << "Weapon ha cambiado de tipo a <" << this->type << ">." << std::endl;
}