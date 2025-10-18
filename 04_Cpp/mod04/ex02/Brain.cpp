/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:09:11 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/18 13:19:52 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain()
{
	cout << "Brain constructor called 👷‍♂️" << endl;
	this->_size = 0;
}

Brain::Brain(const Brain& src)
{
	cout << "Brain copy constructor called 👷‍♂️" << endl;
	*this = src;
}

Brain& Brain::operator=(const Brain& src)
{
	cout << "\n Brain operator = called 🧠" << endl;

	for (int i = 0; i < 100; i++)
		this->_ideas[i] = src._ideas[i];
	this->_size = src._size;
	return *this;
}

Brain::~Brain()
{
	cout << "Brain destructor called 💣" << endl;
}

void Brain::addIdea(std::string idea)
{
	if (this->_size == 100)
	{
		cout << "Brain full of ideas 🤯" << endl;
		return ;
	}
	this->_ideas[this->_size++] = idea;
}

const std::string& Brain::getIdea(unsigned int i) const
{
	return (this->_ideas[i]);
}