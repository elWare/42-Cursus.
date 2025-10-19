/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:31:52 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 13:42:38 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	public:
		AMateria(std::string const& _type);
		AMateria(const AMateria &src);
		virtual ~AMateria();
		virtual const std::string& getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target) = 0;
	protected:
		std::string	_type;
};
