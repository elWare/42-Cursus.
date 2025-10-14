/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 18:10:50 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() : Animal("Cat")
{
	cout << this->_type << " default constructor called 👨‍💻" << endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	cout << this->_type << " copy constructor called 🙇" << endl;
	this->brain = new Brain(*src.brain);
}

Cat::~Cat()
{
	cout << this->_type << " destructor called 🔫" << endl;
	delete this->brain;
}

Animal& Cat::operator=(const Animal& src)
{
	const Cat *srcOther;
	srcOther = dynamic_cast < const Cat *> (&src);
	if (srcOther)
	{
		this->_type = srcOther->getType();
		*this->brain = *srcOther->brain;
	}
	return *this;
}

void Cat::makeSound() const
{
	cout << "Meow 🐱" << endl;
}

Brain *Cat::getBrain() const
{
	return this->brain;
}