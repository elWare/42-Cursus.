/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 17:54:27 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/29 08:37:14 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact()
{
	//std::cout << "Un contacto ha sido creado." << std::endl;
}
Contact::~Contact()
{
	//std::cout << "Un contacto ha sido borrado." << std::endl;
}

// Getter
const std::string& Contact::getFirstName() const
{
	return (this->_firstName);
}

const std::string& Contact::getLastName() const
{
	return (this->_lastName);
}

const std::string& Contact::getNickName() const
{
	return (this->_nickName);
}

const std::string& Contact::getTlfNumber() const
{
	return (this->_tlfNumber);
}

const std::string& Contact::getDarkestSecret() const
{
	return (this->_darkestSecret);
}

// Setter
void Contact::setFirstName(const std::string& firstName)
{
	this->_firstName = firstName;
	//std::cout << "Nombre de contacto establecido a: " << this->_firstName << std::endl;
}

void Contact::setLastName(const std::string& lastName)
{
	this->_lastName = lastName;
	//std::cout << "Apellidos del contacto: " << this->_lastName << std::endl;
}

void Contact::setNickName(const std::string& nickName)
{
	this->_nickName = nickName;
	//std::cout << "Nick del contacto: " << this->_nickName << std::endl;
}

void Contact::setTlfNumber(const std::string& tlfNumber)
{
	this->_tlfNumber = tlfNumber;
	//std::cout << "Telefono: " << this->_tlfNumber << std::endl;
}

void Contact::setDarkestSecret(const std::string& darkestSecret)
{
	this->_darkestSecret = darkestSecret;
	//std::cout << "Secrets" << this->_darkestSecret << std::endl;
}


void Contact::display_full() const 
{
	std::cout << "--- Detalles del Contacto ---" << std::endl;
    std::cout << "Primer Nombre: " << _firstName << std::endl;
    std::cout << "Apellidos:     " << _lastName << std::endl;
    std::cout << "Nick:          " << _nickName << std::endl;
	std::cout << "Tlf:           " << _tlfNumber << std::endl;
	std::cout << "Secret:        " << _darkestSecret << std::endl;
    std::cout << "-----------------------------" << std::endl;
}