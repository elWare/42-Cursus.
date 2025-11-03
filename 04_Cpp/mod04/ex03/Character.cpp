/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 14:17:10 by jumarque          #+#    #+#             */
/*   Updated: 2025/11/03 13:19:47 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

using std::cout;
using std::endl;

Character::Character(const std::string& name) : _name(name), _inventarySize(0)
{
	//cout << "Character " << this->_name << " default constructor called." << endl;
	for (int i = 0; i < 4; i++)
		this->_inventary[i] = NULL;
}

Character::Character(const Character& src) : _name(src._name), _inventarySize(src._inventarySize)
{
	//cout << "Character " << this->_name << " copy constructo called." << std::endl;
	for (int i = 0; i < 4; i++)
		this->_inventary[i] = NULL;
	*this = src;
}

Character& Character::operator=(const Character& src)
{
	if (this == &src)
		return (*this);
	this->_name = src._name;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventary[i])
		{
			delete this->_inventary[i];
			if (src._inventary[i])
				this->_inventary[i] = src._inventary[i]->clone();
			else
				this->_inventary[i] = NULL;
		}
	}
	this->_inventarySize = src._inventarySize;
	//cout << "Character " << this->_name << " assignment operator called." << endl;
	return *this;
}

Character::~Character()
{
	//cout << "Character " << this->_name << " destructor called." << endl;
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventary[i])
	{
			delete this->_inventary[i];
			this->_inventary[i] = NULL;
		}
	}
}

const std::string& Character::getName() const
{
	return this->_name;
}

void Character::equip(AMateria* m) {
	if (!m)
	{
		cout << "Cannot equip a NULL materia." << endl;
		return;
	}
	if (this->_inventarySize >= 4)
	{
		cout << "Character " << this->_name << "'s inventory is full. Cannot equip " << m->getType() << "." << endl;
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		if (this->_inventary[i] == NULL)
		{
			this->_inventary[i] = m;
			this->_inventarySize++;
			return;
		}
	}
	cout << "Character " << this->_name << "'s inventory is full (logic error)." << endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= 4) {
		cout << "Invalid inventory slot " << idx << "." << endl;
		return;
	}
	if (this->_inventary[idx] == NULL) {
		cout << "Slot " << idx << " is already empty." << endl;
		return;
	}
	cout << "Character " << this->_name << " unequipped " << this->_inventary[idx]->getType() << " from slot " << idx << "." << endl;
	this->_inventary[idx] = NULL;
	this->_inventarySize--;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= 4 || this->_inventary[idx] == NULL) {
		cout << "Cannot use materia: Invalid slot " << idx << " or no materia equipped." << endl;
		return;
	}
	this->_inventary[idx]->use(target);
}

AMateria*	Character::getMateria(const int idx)
{
	if (idx >= 0 && idx < 4 && this->_inventary[idx] != NULL)
		return (this->_inventary[idx]);
	return NULL;
}

