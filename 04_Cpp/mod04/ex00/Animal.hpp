/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:49:07 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 18:11:56 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
	public:
		Animal();
		Animal(const Animal& newAnimal);
		virtual ~Animal();
		
		Animal& operator=(const Animal& otherAnimal);
		const	std::string&	getType() const;
		void	setType(const std::string& type);
		virtual void	makeSound() const;

	protected:
		std::string _type;
		Animal(const std::string& type);
};