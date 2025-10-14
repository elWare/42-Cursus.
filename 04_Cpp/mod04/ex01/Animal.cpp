/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:58:28 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 12:59:07 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using std::cout;
using std::endl;

Animal::Animal()
{
	cout << "Animal constructor por defecto ha sido llamado 👨‍💻" << endl;
}

Animal::Animal(const Animal& newAnimal)
{
	cout << "Animal constructor copiar ha si llamado 🙇‍♂️" << endl;
	*this = newAnimal;
}

Animal::Animal(const std::string& type) : _type(type)
{
	cout << "Animal type constructor ha sido llamado 👨‍💻" << endl;
}

Animal::~Animal()
{
	cout << "Animal destructor ha sido llamado 🔥" << endl;
}

Animal&	Animal::operator=(const Animal& otherAnimal)
{
	cout << "Asignación de animal ha sido llamado 🧮" << endl;
	if (this != &otherAnimal)
		this->_type = otherAnimal._type;
	else
		cout << "Auto-asignación detectada 🧨" << endl;
	return *this;
}

const std::string& Animal::getType() const
{
	return this->_type;
}

void	Animal::setType(const std::string& type)
{
	this->_type = type;
}

void	Animal::makeSound() const
{
	cout << "Sonido Animal 🔊" << endl;
}