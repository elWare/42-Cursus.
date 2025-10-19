/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:20:29 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 18:34:23 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

using std::cout;
using std::endl;

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& src) : AMateria("ice")
{
	*this = src;
}

Ice&	Ice::operator=(const Ice& src)
{
	if (this != &src)
		this->_type =  src._type;
	return (*this);
}

Ice::~Ice() {}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	cout << "* shoots an ice bolt at " << target.getName() << " *" << endl;
}