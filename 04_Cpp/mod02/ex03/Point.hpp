/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jumarque <jumarque@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 12:22:37 by jumarque          #+#    #+#             */
/*   Updated: 2025/10/04 12:27:14 by jumarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	private:
		const Fixed	x;
		const Fixed	y;
	public:
		Point(void);
		Point(const Point&);
		Point(const float x, const float y);
		~Point();

		Point&	operator=(const Point &other);

		const Fixed&	getX(void) const;
		const Fixed&	getY(void) const;
};

#endif