/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:15:44 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/14 17:50:29 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat();
		Cat(const Cat& newCat);
		virtual ~Cat();

		Animal& operator=(const Animal& src);

		void	makeSound() const;
		Brain	*getBrain() const;
	
	private:
		Brain	*brain;
};