/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 10:24:27 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/21 12:19:31 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include "Weapon.hpp"

class HumanB
{
	public:
		HumanB(std::string nName);
		~HumanB(void);
		void attack(void);
		void setWeapon(Weapon& nWeapon);
	private:
		std::string	name;
		Weapon*		weapon;
};

#endif