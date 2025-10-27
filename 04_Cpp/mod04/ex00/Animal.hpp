/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 17:49:07 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/27 08:51:21 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Animal
{
	protected:
		std::string _type;
		
	public:
		Animal();
		Animal(const std::string& type);
		Animal(const Animal& newAnimal);
		virtual ~Animal();
		
		Animal& operator=(const Animal& otherAnimal);
		const	std::string&	getType() const;
		void	setType(const std::string& type);
		virtual void	makeSound() const;

};