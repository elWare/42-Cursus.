/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:49:07 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 13:00:41 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Brain.hpp"
#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& newAnimal);
		virtual ~Animal();
		
		virtual Animal& operator=(const Animal& otherAnimal);
		
		const	std::string&	getType() const;
		void	setType(const std::string& type);
		virtual void	makeSound() const;
		virtual Brain *getBrain() const = 0;

	protected:
		std::string _type;
		Animal(const std::string& type);
};