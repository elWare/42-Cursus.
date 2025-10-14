/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 17:56:08 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() : Animal("Dog")
{
	cout << this->_type << " default constructor called 👨‍💻" << endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
	cout << this->_type << " copy constructor called 🙇" << endl;
	this->brain = new Brain(*src.brain);
}

Dog::~Dog()
{
	cout << this->_type << " destructor called 🔫" << endl;
	delete this->brain;
}

Animal& Dog::operator=(const Animal& src)
{
	const Dog *srcOther;
	srcOther = dynamic_cast < const Dog *> (&src);
	if (srcOther)
	{
		this->_type = srcOther->getType();
		*this->brain = *srcOther->brain;
	}
	return *this;
}

void Dog::makeSound() const
{
	cout << "Woof 🐶" << endl;
}

Brain *Dog::getBrain() const
{
	return this->brain;
}