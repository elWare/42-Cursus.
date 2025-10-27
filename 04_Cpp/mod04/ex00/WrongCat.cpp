/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:14:16 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/27 08:49:31 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using std::cout;
using std::endl;

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	cout << this->_type << " default constructor called 🐅" << endl; 
}

WrongCat::WrongCat(const WrongCat& src) : WrongAnimal("WrongCat")
{
	if (this != &src)
		*this = src;
	cout << this->_type << " copy constructor called 🐯" << endl;
}

void WrongCat::makeSound() const
{
	cout << this->_type << " does: Meow meow 🐣" << endl;
}

WrongCat::~WrongCat()
{
	cout << this->_type << " destructor called 🪓" << endl;
}