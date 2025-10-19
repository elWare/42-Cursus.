/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:48:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 13:51:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria(const std::string& type) : _type(type) {}

AMateria::AMateria(const AMateria& src) : _type(src._type) {}

AMateria::~AMateria() {}

const std::string& AMateria::getType() const
{
	return this->_type;
}