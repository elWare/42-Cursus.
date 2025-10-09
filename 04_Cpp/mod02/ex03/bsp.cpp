/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:36:06 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 12:55:35 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

float	area(const Point& a, const Point& b, const Point& c)
{
	float x1, y1;
	float x2, y2;
	float x3, y3;

	x1 = a.getX().toFloat();
	y1 = a.getY().toFloat();
	x2 = b.getX().toFloat();
	y2 = b.getY().toFloat();
	x3 = c.getX().toFloat();
	y3 = c.getY().toFloat();

	return std::abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

bool	bsp(const Point& a, const Point& b, const Point& c, const Point& point){
	
	float A = area(a, b, c);
	float A1 = area(point, b, c);
	float A2 = area(a, point, c);
	float A3 = area(a, b, point);
	return (A == (A1 + A2 + A3));
}