/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:19:47 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 18:28:26 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using std::cout;
using std::endl;

Dog::Dog() : Animal("Dog")
{
	cout << this->_type << "Constructor por defecto ha sido llamado 🐕" << endl; 
}

Dog::Dog(const Dog&) : Animal("Dog")
{
	cout << this->_type << " constructor copia llamado 🐶‍" << endl;
}

void Dog::makeSound() const
{
	cout << this->_type << " suena: Guau guau 🔊" << endl;
}

Dog::~Dog()
{
	cout << this->_type << " destructor llamado 🦖" << endl;
}