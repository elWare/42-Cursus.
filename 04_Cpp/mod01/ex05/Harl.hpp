/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:14 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/02 08:22:15 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

class Harl
{
	public:
		Harl();
		~Harl();
		void	complain(std::string severity);
	
	private:
		struct _handlers
		{
			std::string severity;
			void	(Harl::*f)(void);
		};
		struct _handlers	handlers[4];
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
};

#endif