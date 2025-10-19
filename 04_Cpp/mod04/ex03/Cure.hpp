/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:35:36 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 18:36:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"

class Cure : public AMateria {

	public:

		Cure();
		Cure(const Cure &src);
		Cure & operator=(const Cure &src);
		~Cure();
		AMateria* clone() const;
		void use(ICharacter& target);
};