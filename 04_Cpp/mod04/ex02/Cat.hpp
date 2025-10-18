/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 17:46:29 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 17:52:16 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& src);
		Cat& operator=(const Cat& src);
		Animal& operator=(const Animal& src);
		~Cat();

		void makeSound() const;
		Brain *getBrain() const;

	private:
		Brain *_brain;
};