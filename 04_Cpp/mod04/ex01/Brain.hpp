/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:19:17 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 11:53:34 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Brain
{
	public:
		Brain();
		Brain(const Brain& src);
		~Brain();

		Brain& operator=(const Brain& src);
		
		const std::string& getIdea(unsigned int index) const;
		void addIdea(const std::string& idea);

	private:
		std::string ideas[100];
		unsigned int count;
};