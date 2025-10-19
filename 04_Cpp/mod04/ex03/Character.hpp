/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:03:04 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 14:36:06 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
	public:
		Character(const std::string& name);
		Character(const Character& src);
		Character& operator=(const Character& src);
		~Character();
		
		const	std::string& getName() const;
		void	equip(AMateria* m);
		void	unequip(int idx);
		void	use(int idx, ICharacter& target);

	private:
		std::string _name;
		AMateria*	_inventary[4];
		int			_inventarySize;
};