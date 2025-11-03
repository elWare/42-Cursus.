/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 13:23:31 by jumarque          #+#    #+#             */
/*   Updated: 2025/11/03 13:27:08 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class IMateriaSource
{
	public:
		virtual AMateria*	createMateria(const std::string& type) = 0;
		virtual void		learnMateria(AMateria* src) = 0;
		virtual void		printMaterias() const = 0;
		virtual ~IMateriaSource();
};