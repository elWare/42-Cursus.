/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:53:27 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 12:21:21 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal
{
	public:
		virtual Animal& operator=(const Animal& src) = 0;
		virtual ~Animal();
		const std::string& getType() const;
		void setType(const std::string& type);
		virtual void makeSound() const = 0;
		virtual Brain *getBrain() const = 0;
	protected:
		std::string _type;
};