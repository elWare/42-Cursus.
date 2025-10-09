/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 12:05:12 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 12:18:11 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap(/* args */);
		FragTrap(const std::string& name);
		FragTrap(const FragTrap& newFragTrap);
		~FragTrap();

		using	ClapTrap::operator=;
		void	highFivesGuys(void) const;
};

#endif