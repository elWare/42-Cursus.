/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 08:55:21 by jumarque          #+#    #+#             */
/*   Updated: 2025/09/29 10:00:26 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>
# include <sstream>

class Zombie
{
	public:
		Zombie();
		~Zombie();
		
		void setName(std::string name = "The Unnamed");
		void announce(void);
	private:
		std::string	_name;
};

Zombie* zombieHorde(int N, std::string name);

#endif