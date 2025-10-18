/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:02:53 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 18:33:36 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat()
{
	cout << "Cat constructor called 🐱" << endl;
	this->_type = "Cat";
	this->_brain = new Brain;
}

Cat::~Cat()
{
	cout << "Cat destructor called 🐱" << endl;
	delete this->_brain;
}

Cat::Cat(const Cat &src)
{
	cout << "Cat copy constructor called of: " << this->_type << endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Cat& Cat::operator=(const Cat &src)
{
	cout << "Cat copy constructor called of: " << this->_type << endl;
	this->_type = src._type;
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return *this;
}

Animal& Cat::operator=(const Animal& src)
{
	const Cat	*catOther;
	catOther = dynamic_cast<const Cat *>(&src);
	if (catOther)
	{
		this->_type = catOther->_type;
		delete this->_brain;
		*this->_brain = *catOther->_brain;
	}
	return (*this);
}

Brain *Cat::getBrain() const
{
	return this->_brain;
}

void Cat::makeSound() const
{
	cout << "Meow 🐱" << endl;
}