/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:32:20 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/19 14:10:30 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IMateriaSource.hpp"
#include "AMateria.hpp"

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource &operator=(const MateriaSource &src);
		~MateriaSource();
		virtual void		learnMateria(AMateria *m);
		virtual AMateria*	createMateria(const std::string& type);
		void				printMaterias() const;
		
	private:
		AMateria*	_materias[4];
		int			_materiasSize;
};