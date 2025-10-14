/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 18:15:44 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/09 18:19:36 by jumarque         ###   ########.fr       */
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

		Cat&	operator=(const Cat& otherCat);
		void	makeSound() const;
};