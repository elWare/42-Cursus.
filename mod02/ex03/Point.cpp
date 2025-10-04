/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:28:40 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 12:35:20 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : x(Fixed(0)), y(Fixed(0)) {}

Point::Point (const float x, const float y): x(Fixed(x)), y (Fixed(y)) {}

Point::Point(const Point &other)
{
	*this = other;
}

Point::~Point() {};

Point	&Point::operator=(const Point&)
{
	return (*this);
}

const Fixed& Point::getX(void) const
{
	return (this->x);
}

const Fixed& Point::getY(void) const
{
	return (this->y);
}