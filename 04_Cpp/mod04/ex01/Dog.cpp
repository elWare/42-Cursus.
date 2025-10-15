/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 14:30:46 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() : Animal("Dog")
{
	cout << this->_type << " default constructor 🐶 called 👨‍💻" << endl;
	this->brain = new Brain();
}

Dog::Dog(const Dog& src) : Animal(src)
{
		cout << this->_type << " copy constructor 🐶 called 🙇" << endl;
		this->brain = new Brain(*(src.brain));
}

Dog::~Dog()
{
	cout << this->_type << " destructor 🐶 called 🧨" << endl;
	if (this->brain != NULL)
	{
		delete this->brain;
		this->brain = NULL;
	}
}

Animal& Dog::operator=(const Animal& src)
{
	const Animal *srcOther;
	srcOther = &src;
	if (srcOther)
	{
		cout << "Assigning from another dog 🐶" << endl;
		delete this->brain;
		this->_type = srcOther->getType();
		this->brain = new Brain(*(srcOther->getBrain()));
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