/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:34:55 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/03 12:22:52 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value (0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy construtor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val) : value(val << fractBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : value (static_cast<int>(roundf(val * (1 << fractBits))))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->value) / (1 << fractBits));
}

int Fixed::toInt(void) const
{
	return (this->value >> fractBits);
}

// ----------------- Operadorer sobre carga

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream &operator<<(std::ostream &stream, const Fixed &nbr)
{
		stream << nbr.toFloat();
		return stream;
}