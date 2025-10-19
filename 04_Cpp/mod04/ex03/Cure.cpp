/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:37:19 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 18:38:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using std::cout;
using std::endl;

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure &src) : AMateria("cure")
{
	*this = src;
}

Cure & Cure::operator=(const Cure &src)
{
	this->_type = src._type;
	return *this;
}

Cure::~Cure() {}

AMateria* Cure::clone() const
{
	return new Cure(*this);
}

void Cure::use(ICharacter& target)
{
	cout << "* heals " << target.getName() << "'s wounds *" << endl;
}