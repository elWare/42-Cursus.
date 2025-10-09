/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 12:34:55 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 11:59:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _value (0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy construtor called" << std::endl;
	*this = other;
}

Fixed::Fixed(const int val) : _value(val << _fractBits)
{
	//std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float val) : _value (static_cast<int>(roundf(val * (1 << _fractBits))))
{
	//std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->_value);
}

void Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / (1 << _fractBits));
}

int Fixed::toInt(void) const
{
	return (this->_value >> _fractBits);
}

// ----------------- Operadorer sobre carga

Fixed& Fixed::operator = (const Fixed &other)
{
	//std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->setRawBits(other.getRawBits());
	return *this;
}

std::ostream &operator << (std::ostream &stream, const Fixed &nbr)
{
		stream << nbr.toFloat();
		return stream;
}

bool	Fixed::operator >= (Fixed const &src) const
{
	if (this->_value >= src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator <= (Fixed const &src) const
{
	if (this->_value <= src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator > (Fixed const &src) const
{
	if (this->_value > src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator < (Fixed const &src) const
{
	if (this->_value < src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator == (Fixed const &src) const
{
	if (this->_value == src.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator != (Fixed const &src) const
{
	if (this->_value != src.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator + (Fixed const &other) const
{
	Fixed	result;
	
	result.setRawBits(this->_value + other.getRawBits());
	return (result);
}

Fixed	Fixed::operator-(Fixed const &other) const
{
	Fixed	result;
	
	result.setRawBits(this->_value - other.getRawBits());
	return (result);
}

Fixed	Fixed::operator * (Fixed const &other) const
{
	Fixed	result;
	
	result.setRawBits((this->_value * other.getRawBits()) >> this->_fractBits);
	return (result);
}

Fixed	Fixed::operator / (Fixed const &other) const
{
	Fixed	result;
	if (other.getRawBits() == 0)
	{
		std::cerr << "Error: Division by zero!" << std::endl;
		return *this;
	}
	result.setRawBits((this->_value * (1 << Fixed::_fractBits)) / other.getRawBits());
	return (result);
}

// Operadores de incremento

Fixed	Fixed::operator ++ ()
{
	this->_value++;
	return (*this);
}

Fixed	Fixed::operator ++ (int)
{
	Fixed	tmp(*this);
	++(*this);
	return (tmp);
}

Fixed	Fixed::operator -- ()
{
	this->_value--;
	return (*this);
}

Fixed	Fixed::operator -- (int)
{
	Fixed tmp(*this);
	--(*this);
	return (tmp);
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() > b.getRawBits())
			return b;
	return a;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b) {
	if (a.getRawBits() < b.getRawBits())
			return b;
	return a;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	if (a.getRawBits() > b.getRawBits())
			return b;
	return a;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	if (a.getRawBits() < b.getRawBits())
			return b;
	return a;
}