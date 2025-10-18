/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 18:40:24 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 18:41:37 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog()
{
	cout << "Dog constructor called 🐶" << endl;
	this->_type = "Dog";
	this->_brain = new Brain;
}

Dog::~Dog()
{
	cout << "Dog destructor called 🪓" << endl;
	delete this->_brain;
}

Dog::Dog(const Dog &src)
{
	cout << "Dog copy constructor called of: " << this->_type << endl;
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
}

Dog& Dog::operator=(const Dog &src)
{
	cout << "Dog copy constructor called of: " << this->_type << endl;
	this->_type = src._type;
	delete this->_brain;
	this->_brain = new Brain(*src._brain);
	return *this;
}

Animal& Dog::operator=(const Animal& src)
{
	const Dog	*DogOther;
	DogOther = dynamic_cast<const Dog *>(&src);
	if (DogOther)
	{
		this->_type = DogOther->_type;
		delete this->_brain;
		*this->_brain = *DogOther->_brain;
	}
	return (*this);
}

Brain *Dog::getBrain() const
{
	return this->_brain;
}

void Dog::makeSound() const
{
	cout << "Woof 🐶" << endl;
}