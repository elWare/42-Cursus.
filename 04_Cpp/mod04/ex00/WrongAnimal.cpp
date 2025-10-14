/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:44:57 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 11:55:43 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal()
{
	cout << "WrongAnimal default constructor called 🧑‍🔧." << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& src)
{
	cout << "WrongAnimal copy constructor called 🖨️." << endl;
	*this = src;
}

WrongAnimal::WrongAnimal(const std::string& type) : _type(type)
{
	cout << "WrongAnimal type constructor called 🤖." << endl;
}

WrongAnimal::~WrongAnimal()
{
	cout << "WrongAnimal destructor called 🙀" << endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& src)
{
	cout << "WrongAnimal assignation operator called 🧮." << endl;
	if (this != &src)
		this->_type = src._type;
	else
		cout << "Self-assignamen detected 🧨." << endl;
	return *this;
}

const std::string& WrongAnimal::getType() const
{
	return _type;
}

void WrongAnimal::setType(const std::string& type)
{
	this->_type = type;
}

void WrongAnimal::makeSound() const
{
	cout << "WrongAnimal sound 🐓" << endl;
}