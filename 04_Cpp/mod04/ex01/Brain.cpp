/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 17:27:36 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/15 14:18:59 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using std::cout;
using std::endl;

Brain::Brain()
{
	cout << "Brain default constructor 🧠 called 👨‍💻" << endl;
	this->count = 0;
}

Brain::Brain(const Brain& src)
{
	cout << "Brain copy constructor🧠 called 🙇" << endl;
	for (int i = 0; i < 100; ++i)
		this->ideas[i] = src.ideas[i];
	this->count = src.count;
}

Brain::~Brain()
{
	cout << "Brain Destructor 🧠 called 🧨" << endl;
}

Brain& Brain::operator=(const Brain& src)
{
	if (this == &src)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = src.ideas[i];
	this->count = src.count;
	return *this;
}

const std::string& Brain::getIdea(unsigned int index) const
{
	return this->ideas[index];
}

void Brain::addIdea(const std::string& idea)
{
	if (count == 100)
	{
		cout << "Brain is full" << endl;
		return ;
	}
	this->ideas[count++] = idea;
}