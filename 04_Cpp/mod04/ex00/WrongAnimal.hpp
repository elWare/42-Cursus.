/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:33:37 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 11:39:40 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class WrongAnimal
{
	protected:
		std::string _type;
		WrongAnimal(const std::string& type);

	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal& src);
		virtual ~WrongAnimal();

		WrongAnimal& operator=(const WrongAnimal& src);
		const std::string& getType() const;
		void setType(const std::string& type);
		void makeSound() const;
};
