/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 12:42:25 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/31 12:11:56 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

using	std::cout;
using	std::endl;

MateriaSource::MateriaSource() : _materiasSize(0)
{
	for (int i = 0; i < 4; i++)
		this->_materias[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& src)
{
	*this = src;
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
		{
			delete this->_materias[i];
			this->_materias[i] = NULL;
		}
	}
	//std::cout << "MateriaSource destructor called 💣" << endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource &src)
{
	this->_materiasSize = src._materiasSize;
	for (int i = 0; i < 4 ; i++)
	{
		if (this->_materias[i])
			delete this->_materias[i];
		if (src._materias[i] != NULL)
			this->_materias[i] = src._materias[i]->clone();
		else
			this->_materias[i] = NULL;
	}
	return *this;
}

void	MateriaSource::printMaterias() const
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i])
			cout << i << ": " << this->_materias[i]->getType() << endl;
		else
			cout << i << " is empty" << endl;
	}
}

void MateriaSource::learnMateria(AMateria* m)
{
 	if (m == NULL)
	{
		cout << "Cannot learn a NULL materia." << endl;
		return ;
	}
	if (this->_materiasSize >= 4)
	{
		cout << "MateriaSource is full, cannot learn more materias." << endl;
		delete m;
		return ;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_materias[i] && (this->_materias[i]->getType() == m->getType()))
		{
			cout << "Materia of type " << m->getType() << " already learned." << endl;
			delete m;
			return ;
		}
	}
	this->_materias[this->_materiasSize] = m;
	this->_materiasSize++;
	//cout << "Materia " << m->getType() << " learned successfully." << endl;
}

AMateria *MateriaSource::createMateria(const std::string& type)
{
	for (int i = 0; i < this->_materiasSize; i++)
	{
		if (this->_materias[i] && this->_materias[i]->getType() == type)
		{
			//cout << "Creating a clone of " << type << " materia." << endl;
			return this->_materias[i]->clone();
		}
	}
	cout << "Materia of type " << type << " not found in source." << endl;
	return NULL;
}