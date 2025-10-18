/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:47:25 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 13:04:21 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using std::cout;
using std::endl;

const std::string& Animal::getType(void) const
{
	return (this->_type);
}

void Animal::setType(const std::string& type)
{
	this->_type = type;
}

Animal::~Animal()
{
	cout << "Animal destructor called 🪓" << endl;
}

Animal& Animal::operator=(const Animal& src)
{
	this->_type = src._type;
	return (*this);
}