/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/27 09:29:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using std::cout;
using std::endl;

Cat::Cat() : Animal("Cat")
{
	cout << this->_type << "Constructor por defecto ha sido llamado 🐈" << endl; 
}

Cat::Cat(const Cat&) : Animal("Cat")
{
	cout << this->_type << " constructor copia llamado 🐱" << endl;
}

void Cat::makeSound() const
{
	cout << this->_type << " suena: Meow meow 🔊" << endl;
}

Cat::~Cat()
{
	cout << this->_type << " destructor llamado 🦖" << endl;
}
