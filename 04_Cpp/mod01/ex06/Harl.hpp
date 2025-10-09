/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 18:33:14 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/02 09:10:35 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <string>

# define ARGC_ERR "Invalid arguments\nlevels: DEBUG, INFO, WARNING, ERROR"
# define USAGE "Usage: ./harlFilter <level>\nlevels: DEBUG, INFO, WARNING, ERROR"

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