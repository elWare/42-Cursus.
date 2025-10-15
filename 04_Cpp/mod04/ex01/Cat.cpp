/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 13:43:49 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() : Animal("Cat")
{
	cout << this->_type << " default constructor 🐱 called 👨‍💻" << endl;
	this->brain = new Brain();
}

Cat::Cat(const Cat& src) : Animal(src)
{
	cout << this->_type << " copy constructor 🐱 called 🙇" << endl;
	this->brain = new Brain(*(src.brain));
}

Cat::~Cat()
{
	cout << this->_type << " destructor 🐱 called 🧨" << endl;
	if (this->brain)
	{
		delete this->brain;
		this->brain = NULL;
	}
}

Animal& Cat::operator=(const Animal& src)
{
	const Cat *srcOther;
	srcOther = dynamic_cast < const Cat *> (&src);
	if (srcOther)
	{
		cout << "Assigning from another cat 🐱" << endl;
		
		delete this->brain;		
		this->_type = srcOther->getType();
		this->brain = new Brain(*srcOther->getBrain());
	}
	else
		cout << "Cannot assign from a non-cat 🐱🚫" << endl;
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